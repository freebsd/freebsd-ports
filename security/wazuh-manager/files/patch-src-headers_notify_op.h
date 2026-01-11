--- src/headers/notify_op.h	2026-01-10 15:12:30.071325000 -0800
+++ src/headers/notify_op.h	2026-01-10 15:21:09.287593000 -0800
@@ -24,7 +24,7 @@
     WE_WRITE = 2
 } wevent_t;
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #include <sys/epoll.h>
 
@@ -43,7 +43,7 @@
     return notify->events[index].data.fd;
 }
 
-#elif defined(__MACH__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__MACH__) || defined(__OpenBSD__)
 
 #include <sys/types.h>
 #include <sys/event.h>
@@ -64,7 +64,7 @@
     return notify->events[index].ident;
 }
 
-#endif /* __linux__ */
+#endif /* __linux__ || __FreeBSD__ */
 
 #if defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
