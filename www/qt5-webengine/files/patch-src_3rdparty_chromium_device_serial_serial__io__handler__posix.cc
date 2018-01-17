--- src/3rdparty/chromium/device/serial/serial_io_handler_posix.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/serial/serial_io_handler_posix.cc
@@ -61,7 +61,7 @@ bool BitrateToSpeedConstant(int bitrate,
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
