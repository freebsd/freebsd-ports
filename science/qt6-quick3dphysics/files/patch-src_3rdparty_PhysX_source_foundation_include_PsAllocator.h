Index: src/3rdparty/PhysX/source/foundation/include/PsAllocator.h
--- src/3rdparty/PhysX/source/foundation/include/PsAllocator.h.orig	2023-09-24 11:12:43 UTC
+++ src/3rdparty/PhysX/source/foundation/include/PsAllocator.h
@@ -100,8 +100,10 @@
 #if PX_WINDOWS_FAMILY
 	#include <malloc.h>
 	#define PxAlloca(x) _alloca(x)
-#elif PX_LINUX || PX_ANDROID
+#elif (PX_LINUX || PX_ANDROID) && !defined(PX_FREEBSD)
 	#include <malloc.h>
+	#define PxAlloca(x) alloca(x)
+#elif PX_FREEBSD
 	#define PxAlloca(x) alloca(x)
 #elif PX_APPLE_FAMILY
 	#include <alloca.h>
