--- ./src/util/sss_krb5.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/sss_krb5.c	2011-10-13 12:15:03.000000000 -0400
@@ -165,8 +165,8 @@
 
         if (_realm) {
             *_realm = talloc_asprintf(mem_ctx, "%.*s",
-                                      krb5_princ_realm(ctx, client_princ)->length,
-                                      krb5_princ_realm(ctx, client_princ)->data);
+                                      krb5_realm_length(krb5_princ_realm(krb_ctx, client_princ)),
+                                      krb5_princ_realm(krb_ctx, client_princ));
             if (!*_realm) {
                 DEBUG(1, ("talloc_asprintf failed"));
                 if (_principal) talloc_zfree(*_principal);
@@ -243,7 +243,7 @@
         }
 
         realm_name = talloc_strdup(tmp_ctx, default_realm);
-        krb5_free_default_realm(context, default_realm);
+        free(default_realm);
         if (!realm_name) {
             ret = ENOMEM;
             goto done;
@@ -322,7 +322,7 @@
             found = true;
         }
         free(kt_principal);
-        krberr = krb5_free_keytab_entry_contents(context, &entry);
+        krberr = krb5_kt_free_entry(context, &entry);
         if (krberr) {
             /* This should never happen. The API docs for this function
              * specify only success for this function
@@ -466,7 +466,7 @@
             break;
         }
 
-        kerr = krb5_free_keytab_entry_contents(ctx, &entry);
+        kerr = krb5_kt_free_entry(ctx, &entry);
         if (kerr != 0) {
             DEBUG(1, ("Failed to free keytab entry.\n"));
         }
@@ -504,7 +504,7 @@
     kerr = 0;
 
 done:
-    kerr_d = krb5_free_keytab_entry_contents(ctx, &entry);
+    kerr_d = krb5_kt_free_entry(ctx, &entry);
     if (kerr_d != 0) {
         DEBUG(1, ("Failed to free keytab entry.\n"));
     }
@@ -540,7 +540,7 @@
 void KRB5_CALLCONV sss_krb5_free_error_message(krb5_context ctx, const char *s)
 {
 #ifdef HAVE_KRB5_GET_ERROR_MESSAGE
-    krb5_free_error_message(ctx, s);
+    free(s);
 #else
     free(s);
 #endif
