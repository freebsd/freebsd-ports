--- scribus/plugins/fileloader/oodraw/sxwunzip.cpp.orig	Fri Dec 17 10:17:03 2004
+++ scribus/plugins/fileloader/oodraw/sxwunzip.cpp	Mon Jan 10 20:43:53 2005
@@ -24,6 +24,8 @@
 #include <string.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 # include <unistd.h>
 # include <utime.h>
