--- src/3rdparty/chromium/device/serial/serial_io_handler_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/device/serial/serial_io_handler_posix.cc
@@ -62,7 +62,7 @@ bool BitrateToSpeedConstant(int bitrate, speed_t* spee
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
