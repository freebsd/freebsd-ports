--- src/xine-engine/xine_internal.h.orig	Sat Apr 22 00:46:33 2006
+++ src/xine-engine/xine_internal.h	Thu Sep 28 16:13:27 2006
@@ -72,6 +72,124 @@
 #  include <xine/alphablend.h>
 #endif
 
+#ifndef INT8_MIN
+#define INT8_MIN	(-0x7f-1)
+#endif
+
+#ifndef INT8_MAX
+#define INT8_MAX	0x7f
+#endif
+
+#ifndef INT16_MAX
+#define INT16_MAX 0x7fff
+#endif
+
+#ifndef INT16_MIN
+#define INT16_MIN (-0x7fff-1)
+#endif
+
+#ifndef INT32_MAX
+#define INT32_MAX 0x7fffffff
+#endif
+
+#ifndef INT32_MIN
+#define INT32_MIN (-0x7fffffff-1)
+#endif
+
+#ifndef PRIdMAX
+#define PRIdMAX "lld"
+#endif
+
+#ifndef SCNdMAX
+#define SCNdMAX "lld"
+#endif
+
+#ifndef PRIiMAX
+#define PRIiMAX "lld"
+typedef long long intmax_t;
+#endif
+
+
+#ifndef PRId32
+#define PRId32 "d"
+#endif
+
+#ifndef SCNd32
+#define SCNd32 "d"
+#endif
+
+#ifndef PRIdFAST16
+#define PRIdFAST16 "d"
+#endif
+
+#ifndef PRIdFAST32
+#define PRIdFAST32 "d"
+#endif
+
+#ifndef SCNu32
+#define SCNu32 "u"
+#endif
+
+
+#ifndef PRId64
+#if defined(__alpha__) || defined(__amd64__) || defined(__ia64__) || defined(__sparc64__)
+#define PRId64 "ld"
+#else if defined(__i386__) || defined(__powerpc__)
+#define PRId64 "lld"
+#endif
+#endif
+
+#ifndef SCNd64
+#define SCNd64 PRId64
+#endif
+
+#ifndef PRIu64
+#if defined(__alpha__) || defined(__amd64__) || defined(__ia64__) || defined(__sparc64__)
+#define PRIu64 "lu"
+#else if defined(__i386__) || defined(__powerpc__)
+#define PRIu64 "llu"
+#endif
+#endif
+
+#ifndef SCNu64
+#define SCNu64 PRIu64
+#endif
+
+#ifndef PRIX64
+#if defined(__alpha__) || defined(__amd64__) || defined(__ia64__) || defined(__sparc64__)
+#define PRIX64 "lX"
+#else if defined(__i386__) || defined(__powerpc__)
+#define PRIX64 "llX"
+#endif
+#endif
+
+
+#ifndef PRIx32
+#define	PRIx32	"x"
+#endif
+
+#ifndef PRIx16
+#define	PRIx16	"x"
+#endif
+
+#ifndef PRIx8
+#define	PRIx8	"x"
+#endif
+
+#ifndef PRIXMAX
+#define	PRIXMAX	"llX"
+#endif
+
+#ifndef PRIxMAX
+#define	PRIxMAX	"llx"
+#endif
+
+#ifndef UINT64_C
+#define	UINT64_C(c)	(c ## ULL)
+#endif
+
+
+
 
 #define XINE_MAX_EVENT_LISTENERS         50
 #define XINE_MAX_EVENT_TYPES             100
