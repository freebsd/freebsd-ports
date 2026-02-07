--- contrib/libev/ev.c.orig	2025-06-17 09:32:30 UTC
+++ contrib/libev/ev.c
@@ -527,7 +527,11 @@
 #endif
 
 #if EV_USE_INOTIFY
-# include <sys/statfs.h>
+# ifdef __FreeBSD__
+# include <sys/mount.h>
+# else
+ # include <sys/statfs.h>
+# endif
 # include <sys/inotify.h>
 /* some very old inotify.h headers don't have IN_DONT_FOLLOW */
 # ifndef IN_DONT_FOLLOW
