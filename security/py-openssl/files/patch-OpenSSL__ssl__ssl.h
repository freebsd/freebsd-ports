--- ./OpenSSL/ssl/ssl.h.orig	2011-09-02 17:46:13.000000000 +0200
+++ ./OpenSSL/ssl/ssl.h	2011-09-12 15:49:37.000000000 +0200
@@ -73,4 +73,8 @@
 
 #endif /* SSL_MODULE */
 
+#if !defined(TLSEXT_NAMETYPE_host_name) && defined(__FreeBSD__)
+#define TLSEXT_NAMETYPE_host_name	0
+#endif
+
 #endif /* PyOpenSSL_SSL_H_ */
