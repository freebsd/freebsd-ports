--- lib/sockopt.c.orig	Fri Dec 13 20:15:29 2002
+++ lib/sockopt.c	Mon Jan  5 08:25:17 2004
@@ -197,3 +197,29 @@
 #endif /* #if OS_TYPE */
 
 }
+
+int
+sockopt_tcp_signature (int family, int sock, int enable)
+{
+  int ret;
+
+#ifdef TCP_MD5SIG
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
+#endif /* TCP_MD5SIG */
+
+  /* fallthrough */
+
+  zlog (NULL, LOG_WARNING, "can't set sockopt TCP_MD5SIG on socket %d with family %d",
+                 sock, family);
+  return -1;
+}
