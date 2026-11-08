--- scan_engine_connect.cc.orig	2026-08-20 12:25:01.000000000 -0700
+++ scan_engine_connect.cc	2026-08-20 13:20:39.265109000 -0700
@@ -434,6 +434,14 @@
 #endif
 
   if (!bind_failed && 0 == o.SourceSockAddr(&ss, &sslen)) {
+    // Use the exact protocol-specific length.  Some platforms (e.g. FreeBSD)
+    // reject sizeof(sockaddr_storage) passed to bind() with EINVAL.
+    if (ss.ss_family == AF_INET)
+      sslen = sizeof(struct sockaddr_in);
+#if HAVE_IPV6
+    else if (ss.ss_family == AF_INET6)
+      sslen = sizeof(struct sockaddr_in6);
+#endif
     if (::bind(sd, (struct sockaddr*)&ss, sslen) != 0) {
       error("%s: Problem binding source address (%s), errno: %d", __func__, inet_socktop_safe(&ss), socket_errno());
       perror("bind");
