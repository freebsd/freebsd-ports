--- src/gsIO/gsFileManager.cpp.orig	2021-12-21 18:59:36 UTC
+++ src/gsIO/gsFileManager.cpp
@@ -40,6 +40,10 @@
 #include <limits.h>
 #endif
 
+#if defined __FreeBSD__
+#include <sys/syslimits.h>
+#endif
+
 namespace gismo
 {
 
