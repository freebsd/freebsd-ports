--- ed25519-donna/ed25519-donna-portable.h.orig	2015-03-16 23:50:38 UTC
+++ ed25519-donna/ed25519-donna-portable.h
@@ -20,6 +20,9 @@
 	#include <sys/param.h>
 	#define DONNA_INLINE inline __attribute__((always_inline))
 	#define DONNA_NOINLINE __attribute__((noinline))
+	#if defined(ALIGN)
+		#undef ALIGN
+	#endif
 	#define ALIGN(x) __attribute__((aligned(x)))
 	#define ROTL32(a,b) (((a) << (b)) | ((a) >> (32 - b)))
 	#define ROTR32(a,b) (((a) >> (b)) | ((a) << (32 - b)))
