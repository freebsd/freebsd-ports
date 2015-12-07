--- device/serial/serial_io_handler_posix.cc.orig	2015-10-06 22:42:12.000000000 -0400
+++ device/serial/serial_io_handler_posix.cc	2015-10-14 10:57:52.264932000 -0400
@@ -59,7 +59,7 @@
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
