--- ./modules/misc/inhibit/xscreensaver.c.orig	2010-07-10 19:56:49.000000000 -0400
+++ ./modules/misc/inhibit/xscreensaver.c	2010-07-10 20:05:33.000000000 -0400
@@ -39,7 +39,6 @@
 #include <sys/wait.h>
 #include <fcntl.h>
 #include <signal.h>
-#include <spawn.h>
 
 /*****************************************************************************
  * Local prototypes
@@ -133,14 +132,6 @@
  *****************************************************************************/
 static void Execute (vlc_inhibit_t *p_ih, const char *const *argv)
 {
-    vlc_inhibit_sys_t *p_sys = p_ih->p_sys;
-    pid_t pid;
-
-    if (posix_spawnp (&pid, argv[0], &p_sys->actions, &p_sys->attr,
-                      (char **)argv, environ) == 0)
-    {
-        while (waitpid (pid, NULL, 0) != pid);
-    }
 }
 
 /*****************************************************************************
