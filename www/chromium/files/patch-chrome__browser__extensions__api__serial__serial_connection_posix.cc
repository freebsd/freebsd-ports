--- chrome/browser/extensions/api/serial/serial_connection_posix.cc.orig	2014-02-20 21:27:38.000000000 +0100
+++ chrome/browser/extensions/api/serial/serial_connection_posix.cc	2014-02-24 16:10:53.000000000 +0100
@@ -36,7 +36,7 @@
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)
@@ -71,7 +71,7 @@
     SPEED_TO_BITRATE_CASE(9600)
     SPEED_TO_BITRATE_CASE(19200)
     SPEED_TO_BITRATE_CASE(38400)
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     SPEED_TO_BITRATE_CASE(57600)
     SPEED_TO_BITRATE_CASE(115200)
     SPEED_TO_BITRATE_CASE(230400)
