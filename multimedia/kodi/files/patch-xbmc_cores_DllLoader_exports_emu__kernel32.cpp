--- xbmc/cores/DllLoader/exports/emu_kernel32.cpp.orig	2014-12-20 16:28:10 UTC
+++ xbmc/cores/DllLoader/exports/emu_kernel32.cpp
@@ -38,6 +38,7 @@
 #define __except catch
 #endif
 
+#include <stdlib.h>
 #include <string.h>
 #include <vector>
 using namespace std;
