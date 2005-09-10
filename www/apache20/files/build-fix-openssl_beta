--- modules/ssl/ssl_toolkit_compat.h.orig	Fri Feb  4 21:21:18 2005
+++ modules/ssl/ssl_toolkit_compat.h	Tue Aug 30 01:42:51 2005
@@ -99,6 +99,13 @@
 #define HAVE_SSL_X509V3_EXT_d2i
 #endif
 
+#ifndef PEM_F_DEF_CALLBACK
+#ifdef PEM_F_PEM_DEF_CALLBACK
+/* In OpenSSL 0.9.8 PEM_F_DEF_CALLBACK was renamed */
+#define PEM_F_DEF_CALLBACK PEM_F_PEM_DEF_CALLBACK
+#endif
+#endif
+
 #elif defined (SSLC_VERSION_NUMBER) /* RSA */
 
 /* sslc does not support this function, OpenSSL has since 9.5.1 */
