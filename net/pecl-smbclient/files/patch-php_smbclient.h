Obtained from:	https://github.com/eduardok/libsmbclient-php/commit/a8eab234dd19e32a73740bdd5689e36324b8be5d

--- php_smbclient.h.orig	2018-12-24 15:25:25 UTC
+++ php_smbclient.h
@@ -128,6 +128,14 @@ PHP_FUNCTION(smbclient_fstatvfs);
 #endif
 #endif
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_D void
+#define TSRMLS_DC
+#define TSRMLS_C
+#define TSRMLS_CC
+#define TSRMLS_FETCH()
+#endif
+
 extern php_stream_wrapper php_stream_smb_wrapper;
 php_smbclient_state * php_smbclient_state_new  (php_stream_context *context, int init TSRMLS_DC);
 void                  php_smbclient_state_free (php_smbclient_state *state TSRMLS_DC);
