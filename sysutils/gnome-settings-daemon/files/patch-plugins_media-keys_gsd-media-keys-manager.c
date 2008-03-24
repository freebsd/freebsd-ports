--- plugins/media-keys/gsd-media-keys-manager.c.orig	2008-01-29 15:58:30.000000000 -0600
+++ plugins/media-keys/gsd-media-keys-manager.c	2008-01-29 16:00:55.000000000 -0600
@@ -667,7 +667,11 @@
         if ((command != NULL) && (strcmp (command, "") != 0)) {
                 execute (manager, command, FALSE, FALSE);
         } else {
+#if __FreeBSD__
+                execute (manager, "cdcontrol eject", FALSE, FALSE);
+#else
                 execute (manager, "eject -T", FALSE, FALSE);
+#endif
         }
 
         g_free (command);
@@ -869,7 +873,11 @@
                 do_mail_action (manager);
                 break;
         case SLEEP_KEY:
+#if __FreeBSD__
+                do_sleep_action ("zzz", "xset dpms force off");
+#else
                 do_sleep_action ("apm", "xset dpms force off");
+#endif
                 break;
         case SCREENSAVER_KEY:
                 if ((cmd = g_find_program_in_path ("gnome-screensaver-command"))) {
