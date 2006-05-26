--- lib/quit.cc.orig	Sat May 20 23:56:52 2006
+++ lib/quit.cc	Thu May 25 12:40:10 2006
@@ -21,6 +21,11 @@
 
 #pragma implementation "quit"
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
+
 #include <cerrno>
 #include <cstdarg>
 #include <cstdio>
