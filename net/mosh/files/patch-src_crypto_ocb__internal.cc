--- src/crypto/ocb_internal.cc.orig	2022-10-27 01:18:11 UTC
+++ src/crypto/ocb_internal.cc
@@ -130,10 +130,10 @@
 
 #if _MSC_VER
 	#define bswap64(x) _byteswap_uint64(x)
-#elif HAVE_DECL_BSWAP64
-	/* nothing */
 #elif HAVE_DECL___BUILTIN_BSWAP64
 	#define bswap64(x) __builtin_bswap64(x)           /* GCC 4.3+ */
+#elif HAVE_DECL_BSWAP64
+	/* nothing */
 #else
 	#define bswap32(x)                                              \
 	   ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >>  8) | \
