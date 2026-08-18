--- client/ipa-join.c.orig	2025-01-15 09:52:51 UTC
+++ client/ipa-join.c
@@ -1197,7 +1197,7 @@ join(const char *server, const char *hostname, const c
 
     if (childpid == 0) {
         char *argv[12];
-        char *path = "/usr/sbin/ipa-getkeytab";
+        char *path = "/usr/local/sbin/ipa-getkeytab";
         int arg = 0;
         int err;
 
@@ -1372,7 +1372,7 @@ unenroll_host(const char *server, const char *hostname
     }
     krb5_cc_close(krbctx, ccache);
     ccache = NULL;
-    putenv("KRB5CCNAME=MEMORY:ipa-join");
+    setenv("KRB5CCNAME", "MEMORY:ipa-join", 1);
 
 #ifdef WITH_IPA_JOIN_XML
     rval = xmlrpc_unenroll_host(ipaserver, hostname, quiet);
