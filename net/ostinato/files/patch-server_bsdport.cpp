--- server/bsdport.cpp.orig	2013-09-26 14:38:39.469745242 +0200
+++ server/bsdport.cpp	2013-09-26 14:39:17.060742773 +0200
@@ -26,6 +26,7 @@
 #include <QTime>
 
 #include <errno.h>
+#include <unistd.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
