The definition of CRYPTOPP_BOOL_ALIGN16_ENABLED was incorrect for i386.
For NetBSD, this resulted in the inability to build cryptopp on i386.
On FreeBSD, it built, but deskutils/cdcat choked on it while building on
FreeBSD 10/i386 and FreeBSD 11/i386. (PR: 192199)

--- config.h.orig	2016-10-10 23:49:54 UTC
+++ config.h
@@ -534,12 +534,6 @@ NAMESPACE_END
 # endif
 #endif
 
-#if CRYPTOPP_BOOL_SSE2_INTRINSICS_AVAILABLE || CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE || CRYPTOPP_BOOL_NEON_INTRINSICS_AVAILABLE || defined(CRYPTOPP_X64_MASM_AVAILABLE)
-	#define CRYPTOPP_BOOL_ALIGN16 1
-#else
-	#define CRYPTOPP_BOOL_ALIGN16 0
-#endif
-
 // how to allocate 16-byte aligned memory (for SSE2)
 #if defined(CRYPTOPP_MSVC6PP_OR_LATER)
 	#define CRYPTOPP_MM_MALLOC_AVAILABLE
@@ -553,6 +547,12 @@ NAMESPACE_END
 	#define CRYPTOPP_NO_ALIGNED_ALLOC
 #endif
 
+#if CRYPTOPP_BOOL_SSE2_INTRINSICS_AVAILABLE || CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE || CRYPTOPP_BOOL_NEON_INTRINSICS_AVAILABLE || defined(CRYPTOPP_X64_MASM_AVAILABLE) || !defined(CPRYPTO_NO_ALIGNED_ALLOC)
+	#define CRYPTOPP_BOOL_ALIGN16 1
+#else
+	#define CRYPTOPP_BOOL_ALIGN16 0
+#endif
+
 // Apple always provides 16-byte aligned, and tells us to use calloc
 // http://developer.apple.com/library/mac/documentation/Performance/Conceptual/ManagingMemory/Articles/MemoryAlloc.html
 
