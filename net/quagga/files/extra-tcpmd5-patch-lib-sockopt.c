--- lib/sockopt.c.orig	Tue Jan  4 10:03:36 2005
+++ lib/sockopt.c	Fri Jan 28 17:52:57 2005
@@ -243,6 +243,32 @@
 
 }
 
+int
+sockopt_tcp_signature (int family, int sock, int enable)
+{
+  int ret;
+
+#if defined(QUAGGA_TCP_MD5SIG) && defined(TCP_MD5SIG)
+  if (family == AF_INET)
+    {
+      ret = setsockopt (sock, IPPROTO_TCP, TCP_MD5SIG,
+                        (void *) &enable, sizeof (int));
+      if (ret < 0)
+        {
+          zlog (NULL, LOG_WARNING, "can't set sockopt TCP_MD5SIG %d to socket %d", enable, sock);
+          return -1;
+        }
+      return 0;
+    }
+#endif /* QUAGGA_TCP_MD5SIG */
+
+  /* fallthrough */
+
+  zlog (NULL, LOG_WARNING, "can't set sockopt TCP_MD5SIG on socket %d with family %d",
+                 sock, family);
+  return -1;
+}
+
 static int
 setsockopt_ipv4_ifindex (int sock, int val)
 {
