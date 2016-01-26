--- src/printing.c.orig	2013-05-15 04:23:40 UTC
+++ src/printing.c
@@ -151,8 +151,6 @@ static gint layout_set_headers(PangoLayo
 
 	desc = pango_font_description_from_string(prefs_common_get()->textfont);
 	size = pango_font_description_get_size(desc);
-	pango_font_description_free(desc);
-	desc = gtkut_get_default_font_desc();
 	pango_font_description_set_size(desc, size);
 	pango_layout_set_font_description(layout, desc);
 	pango_font_description_free(desc);
@@ -417,10 +415,6 @@ static void draw_page(GtkPrintOperation 
 	}
 	debug_print("count = %d\n", count);
 
-	desc = gtkut_get_default_font_desc();
-	pango_font_description_set_size(desc, font_size);
-	pango_layout_set_font_description(layout, desc);
-	pango_font_description_free(desc);
 	g_snprintf(buf, sizeof(buf), "- %d -", pinfo->page_nr_per_msg + 1);
 	pango_layout_set_text(layout, buf, -1);
 	pango_layout_set_alignment(layout, PANGO_ALIGN_CENTER);
