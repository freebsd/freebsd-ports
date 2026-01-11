--- src/shared/notify_op.c	2026-01-10 15:21:56.099810000 -0800
+++ src/shared/notify_op.c	2026-01-10 15:22:40.484172000 -0800
@@ -11,7 +11,7 @@
 
 #include <shared.h>
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 wnotify_t * wnotify_init(int size) {
     wnotify_t * notify;
@@ -54,7 +54,7 @@
     return epoll_wait(notify->fd, notify->events, notify->size, timeout);
 }
 
-#elif defined(__MACH__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__MACH__) || defined(__OpenBSD__)
 
 wnotify_t * wnotify_init(int size) {
     wnotify_t * notify;
@@ -99,7 +99,7 @@
     return kevent(notify->fd, NULL, 0, notify->events, notify->size, timeout >= 0 ? &ts : NULL);
 }
 
-#endif /* __linux__ */
+#endif /* __linux__ || __FreeBSD__ */
 
 #if defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
