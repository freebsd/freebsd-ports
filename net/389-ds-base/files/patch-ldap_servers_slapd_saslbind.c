--- ldap/servers/slapd/saslbind.c.orig	2026-04-30 12:45:04 UTC
+++ ldap/servers/slapd/saslbind.c
@@ -23,6 +23,7 @@
 #include <sasl/sasl.h>
 #include <sasl/saslplug.h>
 #include <unistd.h>
+#include <dlfcn.h>
 
 static char *serverfqdn;
 
@@ -684,6 +685,37 @@ ids_sasl_init(void)
     if (result != SASL_OK) {
         slapi_log_err(SLAPI_LOG_CONNS, "ids_sasl_init", "Failed to initialize sasl library\n");
         return result;
+    }
+
+    /*
+     * On platforms where ns-slapd drops privileges within the process (e.g.
+     * FreeBSD, where it starts as root to bind the LDAP port and then switches
+     * to the unprivileged server user), issetugid() becomes true and MIT
+     * Kerberos refuses to honour the KRB5_KTNAME environment variable.  The
+     * GSSAPI acceptor then falls back to the default keytab (/etc/krb5.keytab),
+     * which lacks the ldap/ service key and is not readable by the server user,
+     * so every GSSAPI/GSS-SPNEGO bind fails with "No credentials ...
+     * (Permission denied)".  Register the acceptor keytab explicitly through
+     * the MIT krb5 GSSAPI extension: this is process-local (no global side
+     * effects) and is not gated by the secure-mode check.
+     */
+    {
+        const char *ktname = getenv("KRB5_KTNAME");
+        if (ktname != NULL && *ktname != '\0') {
+            void *gssh = dlopen("libgssapi_krb5.so.2", RTLD_NOW | RTLD_GLOBAL);
+            if (gssh != NULL) {
+                void (*reg_acceptor)(const char *) =
+                    (void (*)(const char *))dlsym(
+                        gssh, "krb5_gss_register_acceptor_identity");
+                if (reg_acceptor != NULL) {
+                    reg_acceptor(ktname);
+                    slapi_log_err(SLAPI_LOG_CONNS, "ids_sasl_init",
+                                  "registered GSSAPI acceptor keytab %s\n",
+                                  ktname);
+                }
+                /* keep gssh open so the registration remains valid */
+            }
+        }
     }
 
     result = sasl_auxprop_add_plugin("iDS", ids_auxprop_plug_init);
