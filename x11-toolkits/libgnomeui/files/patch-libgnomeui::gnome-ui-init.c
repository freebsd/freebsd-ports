--- libgnomeui/gnome-ui-init.c.orig	Sun Mar 20 20:56:32 2005
+++ libgnomeui/gnome-ui-init.c	Sun Mar 20 20:56:36 2005
@@ -492,8 +492,10 @@
                                 gnome_gconf_get_bool ("/desktop/gnome/sound/event_sounds"));
 
         if (new_use_event_sounds && !use_event_sounds) {
+                GDK_THREADS_ENTER();
                 initialize_gtk_signal_relay ();
                 initialize_gnome_signal_relay ();
+                GDK_THREADS_LEAVE();
 	}
 
         use_event_sounds = new_use_event_sounds;
