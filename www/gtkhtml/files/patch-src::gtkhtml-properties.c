
$FreeBSD$

--- src/gtkhtml-properties.c	2001/11/20 09:55:00	1.1
+++ src/gtkhtml-properties.c	2001/11/20 09:56:37
@@ -75,6 +75,59 @@
 	g_free (p);
 }
 
+static gchar *
+get_font_name (const GdkFont * font)
+{
+	Atom font_atom, atom;
+	Bool status;
+
+	font_atom = gdk_atom_intern ("FONT", FALSE);
+
+	if (font->type == GDK_FONT_FONTSET) {
+		XFontStruct **font_structs;
+		gint num_fonts;
+		gchar **font_names;
+
+		num_fonts = XFontsOfFontSet (GDK_FONT_XFONT (font), &font_structs, &font_names);
+		status = XGetFontProperty (font_structs[0], font_atom, &atom);
+	} else {
+		status = XGetFontProperty (GDK_FONT_XFONT (font), font_atom, &atom);
+	}
+
+	if (status) {
+		return gdk_atom_name (atom);
+	}
+
+	return NULL;
+}
+
+static void
+get_default_fonts (gchar **var_name, gchar **fix_name)
+{
+	GtkStyle *style;
+	char *font_name = NULL;
+
+	style = gtk_widget_get_default_style ();
+	if (style->font) {
+		font_name = get_font_name (style->font);
+	}
+
+	if (font_name) {
+		gchar *enc1, *enc2;
+
+		enc1 = html_font_manager_get_attr (font_name, 13);
+		enc2 = html_font_manager_get_attr (font_name, 14);
+
+		*var_name = g_strdup_printf ("-*-helvetica-*-*-*-*-12-*-*-*-*-*-%s-%s", enc1, enc2);
+		*fix_name = g_strdup_printf ("-*-courier-*-*-*-*-12-*-*-*-*-*-%s-%s", enc1, enc2);
+
+		/* printf ("default encoding %s-%s\n%s\n%s\n", enc1, enc2, *var_name, *fix_name); */
+	} else {
+		*var_name = g_strdup ("-*-helvetica-*-*-*-*-12-*-*-*-*-*-*-*");
+		*fix_name = g_strdup ("-*-courier-*-*-*-*-12-*-*-*-*-*-*-*");
+	}
+}
+
 #ifdef GTKHTML_HAVE_GCONF
 #define GET(t,x,prop,f,c) \
         key = g_strconcat (GTK_HTML_GCONF_DIR, x, NULL); \
@@ -180,59 +233,6 @@
 #define GETS(v,s) \
         g_free (p->v); \
         GET(string,v,s)
-
-static gchar *
-get_font_name (const GdkFont * font)
-{
-	Atom font_atom, atom;
-	Bool status;
-
-	font_atom = gdk_atom_intern ("FONT", FALSE);
-
-	if (font->type == GDK_FONT_FONTSET) {
-		XFontStruct **font_structs;
-		gint num_fonts;
-		gchar **font_names;
-
-		num_fonts = XFontsOfFontSet (GDK_FONT_XFONT (font), &font_structs, &font_names);
-		status = XGetFontProperty (font_structs[0], font_atom, &atom);
-	} else {
-		status = XGetFontProperty (GDK_FONT_XFONT (font), font_atom, &atom);
-	}
-
-	if (status) {
-		return gdk_atom_name (atom);
-	}
-
-	return NULL;
-}
-
-static void
-get_default_fonts (gchar **var_name, gchar **fix_name)
-{
-	GtkStyle *style;
-	char *font_name = NULL;
-
-	style = gtk_widget_get_default_style ();
-	if (style->font) {
-		font_name = get_font_name (style->font);
-	}
-
-	if (font_name) {
-		gchar *enc1, *enc2;
-
-		enc1 = html_font_manager_get_attr (font_name, 13);
-		enc2 = html_font_manager_get_attr (font_name, 14);
-
-		*var_name = g_strdup_printf ("-*-helvetica-*-*-*-*-12-*-*-*-*-*-%s-%s", enc1, enc2);
-		*fix_name = g_strdup_printf ("-*-courier-*-*-*-*-12-*-*-*-*-*-%s-%s", enc1, enc2);
-
-		/* printf ("default encoding %s-%s\n%s\n%s\n", enc1, enc2, *var_name, *fix_name); */
-	} else {
-		*var_name = g_strdup ("-*-helvetica-*-*-*-*-12-*-*-*-*-*-*-*");
-		*fix_name = g_strdup ("-*-courier-*-*-*-*-12-*-*-*-*-*-*-*");
-	}
-}
 
 void
 gtk_html_class_properties_load (GtkHTMLClassProperties *p)
