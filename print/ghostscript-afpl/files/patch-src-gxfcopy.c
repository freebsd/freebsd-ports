--- src/gxfcopy.c.orig	Thu Mar 23 13:39:23 2006
+++ src/gxfcopy.c	Fri Mar  9 15:13:31 2007
@@ -2391,7 +2391,7 @@
 	    a[j++] = &cfdata->names[i];
 	}
     }
-    qsort(a, cfdata->num_glyphs, sizeof(int), compare_glyph_names);
+    qsort(a, cfdata->num_glyphs, sizeof(gs_copied_glyph_name_t*), compare_glyph_names);
     for (; j >= 0; j--)
 	cfdata->glyphs[j].order_index = a[j] - cfdata->names;    
     gs_free_object(memory, a, "order_font_data");
