--- ./modules/misc/inhibit/xdg.c.orig	2011-02-02 06:49:43.000000000 -0500
+++ ./modules/misc/inhibit/xdg.c	2011-02-02 06:50:22.000000000 -0500
@@ -26,7 +26,6 @@
 #include <vlc_plugin.h>
 #include <vlc_inhibit.h>
 #include <assert.h>
-#include <spawn.h>
 #include <sys/wait.h>
 
 static int Open (vlc_object_t *);
@@ -134,19 +133,10 @@
             id,
             NULL,
         };
-        pid_t pid;
 
         vlc_mutex_unlock (&p_sys->lock);
-        if (!posix_spawnp (&pid, "xdg-screensaver", NULL, NULL, argv, environ))
-        {
-            int status;
 
-            msg_Dbg (ih, "started xdg-screensaver (PID = %d)", (int)pid);
-            /* Wait for command to complete */
-            while (waitpid (pid, &status, 0) == -1);
-        }
-        else/* We don't handle the error, but busy looping would be worse :( */
-            msg_Warn (ih, "could not start xdg-screensaver");
+        msg_Warn (ih, "could not start xdg-screensaver");
 
         vlc_mutex_lock (&p_sys->lock);
         p_sys->suspended = p_sys->suspend;
