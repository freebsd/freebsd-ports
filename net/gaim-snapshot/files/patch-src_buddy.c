--- src/buddy.c.orig	Thu Oct 17 12:11:51 2002
+++ src/buddy.c	Thu Oct 17 16:58:49 2002
@@ -2231,7 +2231,13 @@
 	if (blist_options & OPT_BLIST_SHOW_IDLETIME)
 		gtk_widget_show(bs->idle);
 
-	style = gtk_style_copy( gtk_rc_get_style(bs->label) );
+	if (gtk_rc_get_style(bs->label) != NULL) {
+	    style = gtk_style_copy( gtk_rc_get_style(bs->label) );
+	} else {
+	    style = gtk_style_new();
+	    gdk_font_unref(gtk_style_get_font(style));
+	    gtk_style_set_font(style, gdk_font_ref(gtk_style_get_font(bs->label->style)));
+	}
 	for (i = 0; i < 5; i++)
 		style->fg[i] = bs->idle->style->fg[i];
 	if ((blist_options & OPT_BLIST_GREY_IDLERS) && (b->idle)) {
