--- ./modules/misc/inhibit/xdg.c.orig	2010-07-10 19:56:31.000000000 -0400
+++ ./modules/misc/inhibit/xdg.c	2010-07-10 20:07:33.000000000 -0400
@@ -25,7 +25,6 @@
 #include <vlc_common.h>
 #include <vlc_plugin.h>
 #include <vlc_inhibit.h>
-#include <spawn.h>
 #include <sys/wait.h>
 
 static int Open (vlc_object_t *);
@@ -123,19 +122,9 @@
             id,
             NULL,
         };
-        pid_t pid;
         int canc = vlc_savecancel ();
 
-        if (!posix_spawnp (&pid, "xdg-screensaver", NULL, NULL, argv, environ))
-        {
-            int status;
-
-            msg_Dbg (ih, "started xdg-screensaver (PID = %d)", (int)pid);
-            /* Wait for command to complete */
-            while (waitpid (pid, &status, 0) == -1);
-        }
-        else/* We don't handle the error, but busy looping would be worse :( */
-            msg_Warn (ih, "could not start xdg-screensaver");
+        msg_Warn (ih, "could not start xdg-screensaver");
         suspended = !suspended;
         vlc_restorecancel (canc);
     }
