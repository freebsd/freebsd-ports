--- src/gtkhtml.c.orig	Wed Apr 16 01:52:24 2003
+++ src/gtkhtml.c	Wed Apr 16 01:52:35 2003
@@ -2677,7 +2677,7 @@
 	add_bindings (klass);
 	gtk_html_accessibility_init ();
 
-	gtk_rc_parse (PREFIX "/share/gtkhtml-" GTKHTML_RELEASE "/keybindingsrc.emacs");
+	gtk_rc_parse (PREFIX "/share/gnome/gtkhtml-" GTKHTML_RELEASE "/keybindingsrc.emacs");
 	html_class->emacs_bindings = gtk_binding_set_find ("gtkhtml-bindings-emacs");
 	read_key_theme (html_class);
 	gconf_client_notify_add (gconf_client_get_default (), "/desktop/gnome/interface/gtk_key_theme",
