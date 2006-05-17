--- lib/output/file.cc.orig	Mon Jun 13 12:21:49 2005
+++ lib/output/file.cc	Tue May 16 15:41:00 2006
@@ -25,8 +25,11 @@
 #include <cstring>
 #include <fcntl.h>
 #include <unistd.h>
-// #include <sys/types.h>
-// #include <sys/stat.h>
+
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
 
 #include <mkdir_p.h>
 #include <output/file.h>
