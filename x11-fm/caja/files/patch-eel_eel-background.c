--- eel/eel-background.c.orig	2020-08-28 11:28:14 UTC
+++ eel/eel-background.c
@@ -36,7 +36,6 @@
 #include <gio/gio.h>
 #include <math.h>
 #include <stdio.h>
-#include <libcaja-private/caja-global-preferences.h>
 
 enum
 {
@@ -427,6 +426,7 @@ set_root_surface (EelBackground *self,
 static void
 init_fade (EelBackground *self)
 {
+    GSettings *mate_background_preferences;
     GtkWidget *widget = self->details->widget;
     gboolean do_fade;
 
@@ -434,8 +434,10 @@ init_fade (EelBackground *self)
         return;
     }
 
+    mate_background_preferences = g_settings_new ("org.mate.background");
     do_fade = g_settings_get_boolean (mate_background_preferences,
                                       MATE_BG_KEY_BACKGROUND_FADE);
+    g_object_unref (mate_background_preferences);
     if (!do_fade) {
     	return;
     }
