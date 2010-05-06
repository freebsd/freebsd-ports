--- ./modules/ssl/ssl_toolkit_compat.h.orig	2006-07-12 03:40:55.000000000 -0400
+++ ./modules/ssl/ssl_toolkit_compat.h	2010-05-06 16:43:34.888290876 -0400
@@ -121,6 +121,13 @@
 #endif
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
