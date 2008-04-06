--- src/imager.cpp.orig	Sat Mar 29 14:13:35 2008
+++ src/imager.cpp	Sat Mar 29 14:34:37 2008
@@ -10,6 +10,8 @@
 #include <stdlib.h>
 #include <err.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <fcntl.h>
