--- src/gtkhtml.c.orig	Mon Aug  2 11:21:24 2004
+++ src/gtkhtml.c	Tue Aug  3 15:19:41 2004
@@ -2955,7 +2955,7 @@
 	add_bindings (klass);
 	gtk_html_accessibility_init ();
 
-	gtk_rc_parse (PREFIX "/share/" GTKHTML_RELEASE_STRING "/keybindingsrc.emacs");
+	gtk_rc_parse (PREFIX "/share/gnome/" GTKHTML_RELEASE_STRING "/keybindingsrc.emacs");
 	html_class->emacs_bindings = gtk_binding_set_find ("gtkhtml-bindings-emacs");
 	read_key_theme (html_class);
 	gconf_client_notify_add (gconf_client_get_default (), "/desktop/gnome/interface/gtk_key_theme",
