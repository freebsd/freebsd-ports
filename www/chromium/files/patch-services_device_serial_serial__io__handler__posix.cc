--- services/device/serial/serial_io_handler_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ services/device/serial/serial_io_handler_posix.cc
@@ -68,7 +68,7 @@ bool BitrateToSpeedConstant(int bitrate, speed_t* spee
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
