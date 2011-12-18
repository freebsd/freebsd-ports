--- tools/TexturePacker/XBTFWriter.cpp.orig
+++ tools/TexturePacker/XBTFWriter.cpp
@@ -26,6 +26,8 @@
 #include "utils/EndianSwap.h"
 #if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #include <memory.h>
 
