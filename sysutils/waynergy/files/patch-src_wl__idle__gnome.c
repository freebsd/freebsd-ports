--- src/wl_idle_gnome.c.orig	2022-12-07 02:05:11 UTC
+++ src/wl_idle_gnome.c
@@ -2,6 +2,8 @@
 #include <signal.h>
 #include <spawn.h>
 
+extern char **environ;
+
 static void inhibit_stop(struct wlIdle *idle)
 {
 	pid_t *inhibitor = idle->state;
