--- src/mlvpn.c.orig	2026-05-23 10:58:16 UTC
+++ src/mlvpn.c
@@ -847,13 +847,17 @@ mlvpn_rtun_start(mlvpn_tunnel_t *t)
                 t->name);
         } else {
             /* Setting fib/routing-table is supported on FreeBSD and OpenBSD only */
-#if defined(HAVE_FREEBSD)
-            if (fib > 0 && setsockopt(fd, SOL_SOCKET, SO_SETFIB, &fib, sizeof(fib)) < 0)
-#elif defined(HAVE_OPENBSD)
-            if (fib > 0 && setsockopt(fd, SOL_SOCKET, SO_RTABLE, &fib, sizeof(fib)) < 0)
+#if defined(HAVE_FREEBSD) || defined(HAVE_OPENBSD)
+            if (fib > 0)
             {
-                log_warn(NULL, "Cannot set FIB %d for kernel socket", fib);
-                goto error;
+#if defined(HAVE_FREEBSD)
+                if (setsockopt(fd, SOL_SOCKET, SO_SETFIB, &fib, sizeof(fib)) < 0) {
+#else
+                if (setsockopt(fd, SOL_SOCKET, SO_RTABLE, &fib, sizeof(fib)) < 0) {
+#endif
+                    log_warn(NULL, "Cannot set FIB %d for kernel socket", fib);
+                    goto error;
+                }
             }
 #endif
             t->fd = fd;
