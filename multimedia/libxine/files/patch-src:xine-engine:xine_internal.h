--- src/xine-engine/xine_internal.h.orig	Thu Dec 30 11:02:18 2004
+++ src/xine-engine/xine_internal.h	Thu Dec 30 11:20:56 2004
@@ -70,6 +70,42 @@
 #  include <xine/info_helper.h>
 #endif
 
+#ifndef INT8_MIN
+#define INT8_MIN	(-0x7f-1)
+#endif
+
+#ifndef INT8_MAX
+#define INT8_MAX	0x7f
+#endif
+
+#ifndef PRIiMAX
+#define PRIiMAX	"lld"
+typedef long long intmax_t;
+#endif
+
+#ifndef	SCNdMAX
+#define SCNdMAX	"lld"
+#endif
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
+#ifndef UINT64_C
+#define	UINT64_C(c)	(c ## ULL)
+#endif
 
 #define XINE_MAX_EVENT_LISTENERS         50
 #define XINE_MAX_EVENT_TYPES             100
