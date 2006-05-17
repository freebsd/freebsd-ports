--- lib/input/file.cc.orig	Mon Jun 13 12:21:49 2005
+++ lib/input/file.cc	Tue May 16 15:39:14 2006
@@ -25,6 +25,11 @@
 #include <fcntl.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
+
 #include <input/file.h>
 
 
