--- services/device/serial/serial_io_handler_posix.cc.orig	2020-05-13 18:39:47 UTC
+++ services/device/serial/serial_io_handler_posix.cc
@@ -36,6 +36,10 @@ struct termios2 {
 
 #endif  // defined(OS_LINUX)
 
+#if defined(OS_BSD)
+#include <sys/serial.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <IOKit/serial/ioss.h>
 #endif
@@ -66,7 +70,7 @@ bool BitrateToSpeedConstant(int bitrate, speed_t* spee
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
