--- src/cicn.h.orig	2014-11-05 22:52:21.000000000 -0800
+++ src/cicn.h	2014-11-05 22:54:42.000000000 -0800
@@ -1,7 +1,9 @@
+#include <inttypes.h>
+
 #define TYPE_cicn	0x6369636e
 
-typedef void *Ptr;
-typedef void **Handle;
+typedef uint32_t Ptr;
+typedef uint32_t Handle;
 typedef guint32 Fixed;
 
 struct Rect {
@@ -39,7 +41,7 @@
 };
 
 typedef struct ColorTable ColorTable;
-typedef ColorTable *CTabPtr, **CTabHandle;
+typedef uint32_t CTabHandle;
 
 struct PixMap {
 	Ptr baseAddr PACKED;		/* pointer to pixels */
