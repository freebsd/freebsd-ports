--- player/main.cpp.bak	Sun May 25 01:24:42 2003
+++ player/main.cpp	Sat Apr  3 21:25:56 2004
@@ -23,6 +23,7 @@
 #include <fcntl.h>
 #ifdef __FreeBSD__
 #include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 #ifdef __NetBSD__
 #include <ieeefp.h>
