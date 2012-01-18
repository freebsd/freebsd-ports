--- ./tools/TexturePacker/XBTFWriter.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./tools/TexturePacker/XBTFWriter.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -24,7 +24,9 @@
 #include <inttypes.h>
 #include "guilib/XBTF.h"
 #include "utils/EndianSwap.h"
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#elif !defined(__APPLE__)
 #include <malloc.h>
 #endif
 #include <memory.h>
