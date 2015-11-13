--- server/bsdport.cpp.orig	2015-06-15 12:41:37 UTC
+++ server/bsdport.cpp
@@ -26,6 +26,7 @@ along with this program.  If not, see <h
 #include <QTime>
 
 #include <errno.h>
+#include <unistd.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
