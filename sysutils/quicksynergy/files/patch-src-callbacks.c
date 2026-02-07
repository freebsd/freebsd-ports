--- src/callbacks.c.orig	2008-07-28 17:56:10.000000000 -0400
+++ src/callbacks.c	2008-12-19 18:34:57.000000000 -0500
@@ -43,9 +43,9 @@
     "</popup>"
     "</ui>\n";
 
-static GtkActionEntry popup_menu_actions[] = {
-    { "ActionSettings", GTK_STOCK_PREFERENCES, N_("Settings"), NULL, NULL, show_main_window },
-    { "ActionQuit",     GTK_STOCK_QUIT,        N_("Quit"),     NULL, NULL, quicksynergy_quit },    
+static const GtkActionEntry popup_menu_actions[] = {
+    { "ActionSettings", GTK_STOCK_PREFERENCES, N_("Settings"), NULL, NULL, G_CALLBACK(show_main_window) },
+    { "ActionQuit",     GTK_STOCK_QUIT,        N_("Quit"),     NULL, NULL, G_CALLBACK(quicksynergy_quit) },    
 };
 #endif
 
