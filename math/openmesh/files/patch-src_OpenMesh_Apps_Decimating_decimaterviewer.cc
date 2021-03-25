--- src/OpenMesh/Apps/Decimating/decimaterviewer.cc.orig	2020-03-12 13:55:53 UTC
+++ src/OpenMesh/Apps/Decimating/decimaterviewer.cc
@@ -44,6 +44,9 @@
 #ifdef _MSC_VER
 #  pragma warning(disable: 4267 4311)
 #endif
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
 #include <iostream>
 #include <fstream>
