--- src/3rdparty/chromium/device/media_transfer_protocol/media_transfer_protocol_manager.h.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/media_transfer_protocol/media_transfer_protocol_manager.h
@@ -15,7 +15,7 @@
 #include "base/memory/ref_counted.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 #error "Only used on Linux and ChromeOS"
 #endif
 
