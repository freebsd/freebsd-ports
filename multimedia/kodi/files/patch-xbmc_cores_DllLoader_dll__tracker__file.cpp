--- xbmc/cores/DllLoader/dll_tracker_file.cpp.orig	2014-12-20 16:27:04 UTC
+++ xbmc/cores/DllLoader/dll_tracker_file.cpp
@@ -23,6 +23,7 @@
 #include "DllLoader.h"
 #include "threads/SingleLock.h"
 #include "utils/log.h"
+#include "stdlib.h"
 
 #ifdef TARGET_POSIX
 #define dll_open open
