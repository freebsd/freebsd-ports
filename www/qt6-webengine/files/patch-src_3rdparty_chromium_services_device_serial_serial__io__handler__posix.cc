--- src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc
@@ -73,7 +73,7 @@ bool BitrateToSpeedConstant(int bitrate, speed_t* spee
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
