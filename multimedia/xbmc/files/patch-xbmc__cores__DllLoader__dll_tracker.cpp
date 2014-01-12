--- xbmc/cores/DllLoader/dll_tracker.cpp.orig	2013-12-27 17:07:11.000000000 +0100
+++ xbmc/cores/DllLoader/dll_tracker.cpp	2013-12-27 17:05:29.000000000 +0100
@@ -24,6 +24,7 @@
 #include "DllLoader.h"
 #include "threads/SingleLock.h"
 #include "utils/log.h"
+#include <stdlib.h>
 
 #ifdef _cplusplus
 extern "C"
