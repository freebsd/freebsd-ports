--- Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp.orig	2021-09-22 23:05:58 UTC
+++ Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp
@@ -28,7 +28,7 @@
 #include "config.h"
 #include <wtf/MemoryPressureHandler.h>
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <wtf/Logging.h>
 #include <wtf/MainThread.h>
