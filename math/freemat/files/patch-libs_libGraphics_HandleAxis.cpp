--- ./libs/libGraphics/HandleAxis.cpp.orig	Thu Dec 28 15:02:22 2006
+++ ./libs/libGraphics/HandleAxis.cpp	Sat Feb 10 00:07:46 2007
@@ -28,6 +28,10 @@
 #include "HandleCommands.hpp"
 #include <qgl.h>
 
+#ifdef __FreeBSD__
+#define log2(x) log(x)/log(2)
+#endif
+
 // Property list & status
 //    activepositionproperty
 //    alim
