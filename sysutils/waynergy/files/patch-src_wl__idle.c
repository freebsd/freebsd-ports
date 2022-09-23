--- src/wl_idle.c.orig	2022-09-07 10:43:08 UTC
+++ src/wl_idle.c
@@ -2,6 +2,7 @@
 #include <signal.h>
 #include <spawn.h>
 
+extern char **environ;
 static pid_t gnome_session_inhibit = -1;
 
 static void gnome_inhibit_stop(void)
