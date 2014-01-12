--- xbmc/cores/DllLoader/dll_tracker_file.cpp.orig	2013-12-27 17:07:01.000000000 +0100
+++ xbmc/cores/DllLoader/dll_tracker_file.cpp	2013-12-27 17:07:36.000000000 +0100
@@ -23,6 +23,7 @@
 #include "DllLoader.h"
 #include "threads/SingleLock.h"
 #include "utils/log.h"
+#include <stdlib.h>
 
 #ifdef TARGET_POSIX
 #define dll_open open
