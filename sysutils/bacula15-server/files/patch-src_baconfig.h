--- src/baconfig.h.orig	2021-02-05 21:23:44 UTC
+++ src/baconfig.h
@@ -45,6 +45,10 @@
  #define tls_psk_default 0
 #endif
 
+#ifndef ENODATA
+#define ENODATA EPIPE
+#endif
+
 #ifndef ETIME
 #define ETIME ETIMEDOUT
 #endif
