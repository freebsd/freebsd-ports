--- src/baconfig.h.orig	2018-08-29 14:09:36 UTC
+++ src/baconfig.h
@@ -38,6 +38,10 @@
 #define have_tls 0
 #endif
 
+#ifndef ENODATA
+#define ENODATA EPIPE
+#endif
+
 #ifndef ETIME
 #define ETIME ETIMEDOUT
 #endif
