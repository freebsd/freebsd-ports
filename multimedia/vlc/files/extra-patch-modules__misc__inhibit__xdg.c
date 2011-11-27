B
--- ./modules/misc/inhibit/xdg.c.orig	2011-11-25 13:17:54.000000000 -0500
+++ ./modules/misc/inhibit/xdg.c	2011-11-25 13:31:37.000000000 -0500
@@ -26,7 +26,6 @@
 #include <vlc_plugin.h>
 #include <vlc_inhibit.h>
 #include <assert.h>
-#include <spawn.h>
 #include <sys/wait.h>
 #include <signal.h>
 
@@ -47,7 +46,6 @@
     vlc_thread_t thread;
     vlc_cond_t update, inactive;
     vlc_mutex_t lock;
-    posix_spawnattr_t attr;
     bool suspend, suspended;
 };
 
@@ -67,18 +65,6 @@
     vlc_mutex_init (&p_sys->lock);
     vlc_cond_init (&p_sys->update);
     vlc_cond_init (&p_sys->inactive);
-    posix_spawnattr_init (&p_sys->attr);
-    /* Reset signal handlers to default and clear mask in the child process */
-    {
-        sigset_t set;
-
-        sigemptyset (&set);
-        posix_spawnattr_setsigmask (&p_sys->attr, &set);
-        sigaddset (&set, SIGPIPE);
-        posix_spawnattr_setsigdefault (&p_sys->attr, &set);
-        posix_spawnattr_setflags (&p_sys->attr, POSIX_SPAWN_SETSIGDEF
-                                              | POSIX_SPAWN_SETSIGMASK);
-    }
     p_sys->suspend = false;
     p_sys->suspended = false;
 
@@ -106,7 +92,6 @@
 
     vlc_cancel (p_sys->thread);
     vlc_join (p_sys->thread, NULL);
-    posix_spawnattr_destroy (&p_sys->attr);
     vlc_cond_destroy (&p_sys->inactive);
     vlc_cond_destroy (&p_sys->update);
     vlc_mutex_destroy (&p_sys->lock);
@@ -149,20 +134,10 @@
             id,
             NULL,
         };
-        pid_t pid;
 
         vlc_mutex_unlock (&p_sys->lock);
-        if (!posix_spawnp (&pid, "xdg-screensaver", NULL, &p_sys->attr,
-                           argv, environ))
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
