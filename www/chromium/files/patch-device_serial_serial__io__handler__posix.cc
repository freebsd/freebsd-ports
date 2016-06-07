--- device/serial/serial_io_handler_posix.cc.orig	2016-04-08 16:02:09 UTC
+++ device/serial/serial_io_handler_posix.cc
@@ -60,7 +60,7 @@ bool BitrateToSpeedConstant(int bitrate,
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
