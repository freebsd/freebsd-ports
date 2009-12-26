--- libgssdp/gssdp-socket-source.c.orig	2009-12-02 12:06:02.000000000 +0100
+++ libgssdp/gssdp-socket-source.c	2009-12-26 13:55:10.000000000 +0100
@@ -154,6 +154,16 @@
                 if (res == -1)
                         goto error;
 
+#ifdef __FreeBSD__
+                res = setsockopt (socket_source->poll_fd.fd,
+                                  SOL_SOCKET,
+                                  SO_REUSEPORT,
+                                  &boolean,
+                                  sizeof (boolean));
+                if (res == -1)
+                        goto error;
+#endif
+
                 /* Subscribe to multicast channel */
                 res = inet_aton (SSDP_ADDR, &(mreq.imr_multiaddr));
                 if (res == 0)
