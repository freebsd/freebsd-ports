--- lib/simple_version_tool/checkin.cc.orig	Mon Jun 13 12:21:49 2005
+++ lib/simple_version_tool/checkin.cc	Tue May 16 15:50:51 2006
@@ -24,6 +24,11 @@
 #include <cstdio>
 #include <pwd.h>
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#include <sys/types.h>
+#endif
+
 #include <adler32.h>
 #include <careful.h>
 #include <input/file.h>
