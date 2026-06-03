--- media_softlet/linux/common/os/osservice/mos_utilities_specific.h.orig	2026-03-19 10:15:05 UTC
+++ media_softlet/linux/common/os/osservice/mos_utilities_specific.h
@@ -27,7 +27,6 @@
 #define __MOS_UTILITIES_SPECIFIC_H__
 
 #include <map>
-#include <malloc.h>
 #include <string>
 #include "mos_defs.h"
 #include "media_class_trace.h"
@@ -36,7 +35,7 @@
 
 #define NOT_FOUND            -1
 
-#define _aligned_malloc(size, alignment)  memalign(alignment, size)
+#define _aligned_malloc(size, alignment)  aligned_alloc(alignment, size)
 #define _aligned_free(ptr)                free(ptr)
 
 typedef void (*MOS_UserFeatureCallback)( void*, bool);
