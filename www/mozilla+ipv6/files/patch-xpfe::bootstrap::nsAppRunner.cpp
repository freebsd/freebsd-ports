--- xpfe/bootstrap/nsAppRunner.cpp.orig	Mon Nov 26 16:53:29 2001
+++ xpfe/bootstrap/nsAppRunner.cpp	Mon Nov 26 16:54:12 2001
@@ -1060,7 +1060,7 @@
 
 #if defined(FREEBSD)
 // pick up fpsetmask prototype.
-#include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 
 // Note: nativeApp is an owning reference that this function has responsibility
