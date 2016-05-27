--- src/mlvpn.c.orig	2015-12-28 11:20:16 UTC
+++ src/mlvpn.c
@@ -597,7 +597,7 @@ mlvpn_rtun_write(EV_P_ ev_io *w, int rev
 
 mlvpn_tunnel_t *
 mlvpn_rtun_new(const char *name,
-               const char *bindaddr, const char *bindport,
+               const char *bindaddr, const char *bindport, uint32_t bindfib,
                const char *destaddr, const char *destport,
                int server_mode, uint32_t timeout,
                int fallback_only, uint32_t bandwidth,
@@ -653,6 +653,7 @@ mlvpn_rtun_new(const char *name,
         strlcpy(new->bindaddr, bindaddr, sizeof(new->bindaddr));
     if (bindport)
         strlcpy(new->bindport, bindport, sizeof(new->bindport));
+	new->bindfib = bindfib;
     if (destaddr)
         strlcpy(new->destaddr, destaddr, sizeof(new->destaddr));
     if (destport)
@@ -780,6 +781,7 @@ static int
 mlvpn_rtun_start(mlvpn_tunnel_t *t)
 {
     int ret, fd = -1;
+	int fib = 0;
     char *addr, *port;
     struct addrinfo hints, *res;
 
@@ -788,9 +790,11 @@ mlvpn_rtun_start(mlvpn_tunnel_t *t)
     {
         addr = t->bindaddr;
         port = t->bindport;
+		fib = t->bindfib;
     } else {
         addr = t->destaddr;
         port = t->destport;
+		fib = t->bindfib;
     }
 
     /* Initialize hints */
@@ -817,6 +821,14 @@ mlvpn_rtun_start(mlvpn_tunnel_t *t)
             log_warn(NULL, "%s socket creation error",
                 t->name);
         } else {
+#if defined(HAVE_FREEBSD) || defined(HAVE_OPENBSD)
+			/* Setting SO_SETFIB (fib) supported on FreeBSD and OpenBSD only */
+			if (setsockopt(fd, SOL_SOCKET, SO_SETFIB, &fib, sizeof(fib)) < 0)
+			{
+      			log_warnx(NULL, "Cannot set FIB %d for kernel socket", fib);
+				goto error;
+			}
+#endif
             t->fd = fd;
             break;
         }
