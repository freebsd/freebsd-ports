Fix bind key for new ThunarWindow reload signal

--- thunar/thunar-window.c.orig	2015-04-18 14:25:18 UTC
+++ thunar/thunar-window.c
@@ -623,7 +623,7 @@ thunar_window_class_init (ThunarWindowCl
   /* setup the key bindings for the windows */
   binding_set = gtk_binding_set_by_class (klass);
   gtk_binding_entry_add_signal (binding_set, GDK_BackSpace, 0, "back", 0);
-  gtk_binding_entry_add_signal (binding_set, GDK_F5, 0, "reload", 0);
+  gtk_binding_entry_add_signal (binding_set, GDK_F5, 0, "reload", 1, G_TYPE_BOOLEAN, TRUE);
   gtk_binding_entry_add_signal (binding_set, GDK_F9, 0, "toggle-sidepane", 0);
   gtk_binding_entry_add_signal (binding_set, GDK_F10, 0, "toggle-menubar", 0);
   gtk_binding_entry_add_signal (binding_set, GDK_KP_Add, GDK_CONTROL_MASK, "zoom-in", 0);
