--- device/serial/serial_io_handler_posix.cc.orig	2015-07-15 16:30:04.000000000 -0400
+++ device/serial/serial_io_handler_posix.cc	2015-07-22 07:27:41.841184000 -0400
@@ -61,7 +61,7 @@
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
@@ -99,7 +99,7 @@
     SPEED_TO_BITRATE_CASE(9600)
     SPEED_TO_BITRATE_CASE(19200)
     SPEED_TO_BITRATE_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     SPEED_TO_BITRATE_CASE(57600)
     SPEED_TO_BITRATE_CASE(115200)
     SPEED_TO_BITRATE_CASE(230400)
@@ -131,7 +131,7 @@
     return false;
   }
   return true;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   speed_t speed = static_cast<speed_t>(bitrate);
   cfsetispeed(config, speed);
   cfsetospeed(config, speed);
