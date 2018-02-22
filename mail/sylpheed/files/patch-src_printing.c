--- src/printing.c.orig	2017-11-15 04:12:56 UTC
+++ src/printing.c
@@ -154,8 +154,6 @@ static gint layout_set_headers(PangoLayo
 
 	desc = pango_font_description_from_string(prefs_common_get()->textfont);
 	size = pango_font_description_get_size(desc);
-	pango_font_description_free(desc);
-	desc = gtkut_get_default_font_desc();
 	debug_print("layout_set_headers: using font %s (style %d, %g pt)\n", pango_font_description_get_family(desc), pango_font_description_get_style(desc), (gdouble)size / PANGO_SCALE);
 	pango_font_description_set_size(desc, size);
 	pango_layout_set_font_description(layout, desc);
@@ -433,10 +431,6 @@ static void draw_page(GtkPrintOperation 
 	}
 	debug_print("count = %d\n", count);
 
-	desc = gtkut_get_default_font_desc();
-	pango_font_description_set_size(desc, font_size);
-	pango_layout_set_font_description(layout, desc);
-	pango_font_description_free(desc);
 	g_snprintf(buf, sizeof(buf), "- %d -", pinfo->page_nr_per_msg + 1);
 	pango_layout_set_text(layout, buf, -1);
 	pango_layout_set_alignment(layout, PANGO_ALIGN_CENTER);
