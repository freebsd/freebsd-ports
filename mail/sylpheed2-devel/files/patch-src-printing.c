--- src/printing.c.orig	Wed Dec 27 15:50:14 2006
+++ src/printing.c	Wed Dec 27 16:28:28 2006
@@ -149,8 +149,6 @@
 
 	desc = pango_font_description_from_string(prefs_common_get()->textfont);
 	size = pango_font_description_get_size(desc);
-	pango_font_description_free(desc);
-	desc = gtkut_get_default_font_desc();
 	pango_font_description_set_size(desc, size);
 	pango_layout_set_font_description(layout, desc);
 	pango_font_description_free(desc);
@@ -406,10 +404,6 @@
 	}
 	g_print("count = %d\n", count);
 
-	desc = gtkut_get_default_font_desc();
-	pango_font_description_set_size(desc, font_size);
-	pango_layout_set_font_description(layout, desc);
-	pango_font_description_free(desc);
 	g_snprintf(buf, sizeof(buf), "- %d -", pinfo->page_nr_per_msg + 1);
 	pango_layout_set_text(layout, buf, -1);
 	pango_layout_set_alignment(layout, PANGO_ALIGN_CENTER);
