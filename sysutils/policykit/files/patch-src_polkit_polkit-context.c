--- src/polkit/polkit-context.c.orig	2012-03-04 18:35:51.000000000 -0500
+++ src/polkit/polkit-context.c	2012-03-04 18:38:35.000000000 -0500
@@ -45,7 +45,8 @@
 #else
 #ifdef HAVE_INOTIFY
 #include <sys/inotify.h>
-#elif HAVE_KQUEUE
+#endif
+#ifdef HAVE_KQUEUE
 #include <sys/event.h>
 #include <sys/time.h>
 #include <fcntl.h>
@@ -123,7 +124,8 @@ struct _PolKitContext
         int inotify_config_wd;
         int inotify_policy_wd;
         int inotify_grant_perm_wd;
-#elif HAVE_KQUEUE
+#endif
+#ifdef HAVE_KQUEUE
 	int kqueue_fd;
 	int kqueue_fd_watch_id;
 	int kqueue_config_fd;
