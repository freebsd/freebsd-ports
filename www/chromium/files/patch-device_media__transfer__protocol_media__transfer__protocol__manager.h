--- device/media_transfer_protocol/media_transfer_protocol_manager.h.orig	2016-07-17 14:17:13.836047000 +0300
+++ device/media_transfer_protocol/media_transfer_protocol_manager.h	2016-07-17 14:16:48.004323000 +0300
@@ -15,7 +15,7 @@
 #include "base/memory/ref_counted.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 #error "Only used on Linux and ChromeOS"
 #endif
 
