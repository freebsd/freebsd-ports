--- src/support/filetools.cpp	2026-09-07 18:54:34 UTC
+++ src/support/filetools.cpp
@@ -68,6 +68,8 @@
 #include <windows.h>
 #endif
 
+#include <sys/wait.h>
+
 using namespace std;
 
 #define USE_QPROCESS
