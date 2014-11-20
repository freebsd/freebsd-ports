--- device/media_transfer_protocol/media_transfer_protocol_manager.h.orig	2014-10-23 00:53:03.000000000 +0200
+++ device/media_transfer_protocol/media_transfer_protocol_manager.h	2014-10-26 11:53:02.000000000 +0100
@@ -12,8 +12,8 @@
 #include "base/memory/ref_counted.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
-#error "Only used on Linux and ChromeOS"
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
+#error "Only used on Linux and ChromeOS and FreeBSD"
 #endif
 
 class MtpFileEntry;
