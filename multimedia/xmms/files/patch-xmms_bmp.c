--- xmms/bmp.c.orig	2006-07-16 13:40:04 UTC
+++ xmms/bmp.c
@@ -19,6 +19,12 @@
  */
 #include "xmms.h"
 
+#if HAVE_STDINT_H
+#include <stdint.h>
+#elif !defined(UINT32_MAX)
+#define UINT32_MAX 0xffffffffU
+#endif
+
 struct rgb_quad
 {
 	guchar rgbBlue;
@@ -183,7 +189,7 @@ GdkPixmap *read_bmp(gchar * filename)
 	}
 	else if (bitcount != 24 && bitcount != 16 && bitcount != 32)
 	{
-		gint ncols, i;
+		guint32 ncols, i;
 
 		ncols = offset - headSize - 14;
 		if (headSize == 12)
@@ -201,9 +207,17 @@ GdkPixmap *read_bmp(gchar * filename)
 		}
 	}
 	fseek(file, offset, SEEK_SET);
+	/* verify buffer size */
+	if (!h || !w ||
+	    w > (((UINT32_MAX - 3) / 3) / h) ||
+	    h > (((UINT32_MAX - 3) / 3) / w)) {
+		g_warning("read_bmp(): width(%u)*height(%u) too large", w, h);
+		fclose(file);
+		return NULL;
+	}
+	data = g_malloc0((w * 3 * h) + 3);	/* +3 is just for safety */
 	buffer = g_malloc(imgsize);
 	fread(buffer, imgsize, 1, file);
-	data = g_malloc0((w * 3 * h) + 3);	/* +3 is just for safety */
 
 	if (bitcount == 1)
 		read_1b_rgb(buffer, imgsize, data, w, h, rgb_quads);
