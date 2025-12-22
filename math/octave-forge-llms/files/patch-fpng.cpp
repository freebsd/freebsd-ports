--- fpng.cpp.orig	2025-12-22 13:08:02 UTC
+++ fpng.cpp
@@ -79,13 +79,13 @@
 	#endif
 
 	// Assume little endian on Windows/x86/x64.
-	#define __BYTE_ORDER __LITTLE_ENDIAN
+	#define __BYTE_ORDER__ __LITTLE_ENDIAN
 #elif defined(__APPLE__)
-	#define __BYTE_ORDER __BYTE_ORDER__
+	#define __BYTE_ORDER__ __BYTE_ORDER__
 	#define __LITTLE_ENDIAN __LITTLE_ENDIAN__
 	#define __BIG_ENDIAN __BIG_ENDIAN__
 #else
-	// for __BYTE_ORDER (__LITTLE_ENDIAN or __BIG_ENDIAN)
+	// for __BYTE_ORDER__ (__LITTLE_ENDIAN or __BIG_ENDIAN)
 	#include <sys/param.h>
 
 	#ifndef __LITTLE_ENDIAN
@@ -96,8 +96,8 @@
 	#endif
 #endif
 
-#if !defined(__BYTE_ORDER)
-	#error __BYTE_ORDER undefined. Compile with -D__BYTE_ORDER=1234 for little endian or -D__BYTE_ORDER=4321 for big endian.
+#if !defined(__BYTE_ORDER__)
+	#error __BYTE_ORDER__ undefined. Compile with -D__BYTE_ORDER=1234 for little endian or -D__BYTE_ORDER=4321 for big endian.
 #endif
 
 namespace fpng
@@ -131,7 +131,7 @@ namespace fpng
 	}
 
 #if FPNG_USE_UNALIGNED_LOADS
-	#if __BYTE_ORDER == __BIG_ENDIAN
+	#if __BYTE_ORDER__ == __BIG_ENDIAN
 		#define READ_LE32(p) swap32(*reinterpret_cast<const uint32_t *>(p))
 		#define WRITE_LE32(p, v) *reinterpret_cast<uint32_t *>(p) = swap32((uint32_t)(v))
 		#define WRITE_LE64(p, v) *reinterpret_cast<uint64_t *>(p) = swap64((uint64_t)(v))
