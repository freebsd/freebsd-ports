--- xbmc/cores/DllLoader/dll_tracker.cpp.orig	2014-12-20 16:26:59 UTC
+++ xbmc/cores/DllLoader/dll_tracker.cpp
@@ -24,6 +24,7 @@
 #include "DllLoader.h"
 #include "threads/SingleLock.h"
 #include "utils/log.h"
+#include "stdlib.h"
 
 #ifdef _cplusplus
 extern "C"
