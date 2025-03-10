--- src/support/filetools.cpp.orig	2024-11-04 08:57:40.352928000 +0000
+++ src/support/filetools.cpp	2024-11-04 08:59:06.840603000 +0000
@@ -71,6 +71,8 @@
 #include <windows.h>
 #endif
 
+#include <sys/wait.h>
+
 using namespace std;
 
 #define USE_QPROCESS
