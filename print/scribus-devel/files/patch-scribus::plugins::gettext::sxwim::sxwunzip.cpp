--- scribus/plugins/gettext/sxwim/sxwunzip.cpp.orig	Wed Dec 15 05:46:22 2004
+++ scribus/plugins/gettext/sxwim/sxwunzip.cpp	Mon Jan 10 20:34:50 2005
@@ -26,6 +26,8 @@
 #include <string.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #include <utime.h>
 
