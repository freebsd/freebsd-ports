--- src/wrap.h.orig	Fri Oct 26 15:08:54 2001
+++ src/wrap.h	Sun Oct 28 11:06:48 2001
@@ -28,6 +28,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <dirent.h>
+#include <unistd.h>
 
 int m_open(const char *pathname, int flags, mode_t mode);
 
