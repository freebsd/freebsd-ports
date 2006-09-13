--- ext/faad/gstfaad.c.orig	Wed Sep 13 15:26:13 2006
+++ ext/faad/gstfaad.c	Wed Sep 13 15:25:46 2006
@@ -37,6 +37,9 @@
  * but not all, hence this Truly Evil Hack. This hack will need updating if
  * upstream ever releases something with the new API.
  */
+#include <faad.h>
+#include "gstfaad.h"
+#if 0
 #define faacDecInit faadDecInit_no_definition
 #define faacDecInit2 faadDecInit2_no_definition
 #include "gstfaad.h"
@@ -46,7 +49,7 @@
 extern long faacDecInit (faacDecHandle, guint8 *, guint32, guint32 *, guint8 *);
 extern int8_t faacDecInit2 (faacDecHandle, guint8 *, guint32,
     guint32 *, guint8 *);
-
+#endif
 
 GST_DEBUG_CATEGORY_STATIC (faad_debug);
 #define GST_CAT_DEFAULT faad_debug
