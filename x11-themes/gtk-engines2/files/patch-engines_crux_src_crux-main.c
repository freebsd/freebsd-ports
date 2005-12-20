--- engines/crux/src/crux-main.c.orig	Tue Dec 20 13:02:45 2005
+++ engines/crux/src/crux-main.c	Tue Dec 20 13:02:49 2005
@@ -23,7 +23,6 @@
 G_MODULE_EXPORT void
 theme_exit(void)
 {
-  uninstall_all_focus_hooks();
 }
     
 G_MODULE_EXPORT GtkRcStyle *
