--- ext/faad/gstfaad.c.orig	Tue Sep 12 22:48:28 2006
+++ ext/faad/gstfaad.c	Wed Sep 13 06:32:15 2006
@@ -38,15 +38,19 @@
  * but not all, hence this Truly Evil Hack. This hack will need updating if
  * upstream ever releases something with the new API.
  */
+#include <neaacdec.h>
+#include "gstfaad.h"
+
+#if 0
 #define faacDecInit faacDecInit_no_definition
 #define faacDecInit2 faacDecInit2_no_definition
-#include "gstfaad.h"
 #undef faacDecInit
 #undef faacDecInit2
 
 extern long faacDecInit (faacDecHandle, guint8 *, guint32, guint32 *, guint8 *);
 extern int8_t faacDecInit2 (faacDecHandle, guint8 *, guint32,
     guint32 *, guint8 *);
+#endif
 
 GST_DEBUG_CATEGORY_STATIC (faad_debug);
 #define GST_CAT_DEFAULT faad_debug
