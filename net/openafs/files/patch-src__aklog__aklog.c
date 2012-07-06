diff --git a/src/aklog/aklog.c b/src/aklog/aklog.c
index 43db12f..4e2b2de 100644
--- a/src/aklog/aklog.c
+++ b/src/aklog/aklog.c
@@ -216,12 +216,11 @@ Done:
 #error "Must have either keyblock or session member of krb5_creds"
 #endif

-#ifdef AFS_DARWIN110_ENV
-#define HAVE_NO_KRB5_524 /* MITKerberosShim logs but returns success */
+/* MITKerberosShim logs but returns success */
+#if !defined(HAVE_KRB5_524_CONV_PRINCIPAL) || defined(AFS_DARWIN110_ENV) || (!defined(HAVE_KRB5_524_CONVERT_CREDS) && !defined(HAVE_KRB524_CONVERT_CREDS_KDC))
+#define HAVE_NO_KRB5_524
 #elif !defined(HAVE_KRB5_524_CONVERT_CREDS) && defined(HAVE_KRB524_CONVERT_CREDS_KDC)
 #define krb5_524_convert_creds krb524_convert_creds_kdc
-#elif !defined(HAVE_KRB5_524_CONVERT_CREDS) && !defined(HAVE_KRB524_CONVERT_CREDS_KDC)
-#define HAVE_NO_KRB5_524
 #endif

 #if USING_HEIMDAL
