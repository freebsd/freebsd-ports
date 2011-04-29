--- src/zm_comms.cpp.orig	2009-03-20 15:07:00.000000000 +0300
+++ src/zm_comms.cpp	2011-04-08 17:48:07.408806977 +0400
@@ -25,7 +25,7 @@
 #include <fcntl.h>
 #include <stdarg.h>
 //#include <memory.h>
-#include <alloca.h>
+#include <stdlib.h>
 #include <string.h>
 //#include <unistd.h>
 #include <sys/ioctl.h>
