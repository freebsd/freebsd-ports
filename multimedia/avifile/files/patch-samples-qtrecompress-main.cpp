--- samples/qtrecompress/main.cpp.bak	Tue May 27 17:27:19 2003
+++ samples/qtrecompress/main.cpp	Sat Apr  3 21:31:14 2004
@@ -12,6 +12,7 @@
 
 #ifdef __FreeBSD__
 #include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 #ifdef __NetBSD__
 #include <ieeefp.h>
