--- ssl/test/handshake_util.h.orig	2022-01-03 17:26:22 UTC
+++ ssl/test/handshake_util.h
@@ -22,7 +22,7 @@
 #include "settings_writer.h"
 
 
-#if defined(OPENSSL_LINUX) && !defined(OPENSSL_ANDROID)
+#if defined(OPENSSL_LINUX) || defined(OPENSSL_FREEBSD) && !defined(OPENSSL_ANDROID)
 #define HANDSHAKER_SUPPORTED
 #endif
 
