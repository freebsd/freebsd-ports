--- test/CubeView.cpp.orig	Fri Feb 27 04:40:14 2004
+++ test/CubeView.cpp	Fri Feb 27 04:40:41 2004
@@ -25,7 +25,7 @@
 
 #include "CubeView.h"
 
-#ifndef __linux
+#if !defined(__linux) && !defined(__FreeBSD__)
 # include <math.h>
 #endif
 
