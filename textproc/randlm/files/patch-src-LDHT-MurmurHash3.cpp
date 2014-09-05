--- ./src/LDHT/MurmurHash3.cpp.bak	2012-03-30 14:53:05.000000000 +0400
+++ ./src/LDHT/MurmurHash3.cpp	2014-08-30 17:56:33.000000000 +0400
@@ -29,7 +29,7 @@
 
 #else	// defined(_MSC_VER)
 
-#define	FORCE_INLINE __attribute__((always_inline))
+#define	FORCE_INLINE inline __attribute__((always_inline))
 
 inline uint32_t rotl32 ( uint32_t x, int8_t r )
 {
