--- src/gtkhtml.c.orig	Mon Aug 22 15:56:46 2005
+++ src/gtkhtml.c	Mon Aug 22 18:56:03 2005
@@ -3104,7 +3104,7 @@
 	add_bindings (klass);
 	gtk_html_accessibility_init ();
 
-	filename = g_build_filename (PREFIX, "share", GTKHTML_RELEASE_STRING, "keybindingsrc.emacs", NULL);
+	filename = g_build_filename (PREFIX, "share/gnome", GTKHTML_RELEASE_STRING, "keybindingsrc.emacs", NULL);
 	gtk_rc_parse (filename);
 	g_free (filename);
 	html_class->emacs_bindings = gtk_binding_set_find ("gtkhtml-bindings-emacs");
