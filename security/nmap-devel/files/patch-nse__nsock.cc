--- nse_nsock.cc.orig	2026-08-20 12:25:01.000000000 -0700
+++ nse_nsock.cc	2026-08-20 13:20:39.264571000 -0700
@@ -425,6 +425,14 @@
       if (nu->source_addr.ss_family != AF_UNSPEC) {
         nsock_iod_set_localaddr(nu->nsiod, &nu->source_addr, nu->source_addrlen);
       } else if (0 == o.SourceSockAddr(&ss, &sslen)) {
+        // Use the exact protocol-specific length.  Some platforms (e.g. FreeBSD)
+        // reject sizeof(sockaddr_storage) passed to bind() with EINVAL.
+        if (ss.ss_family == AF_INET)
+          sslen = sizeof(struct sockaddr_in);
+#if HAVE_IPV6
+        else if (ss.ss_family == AF_INET6)
+          sslen = sizeof(struct sockaddr_in6);
+#endif
         nsock_iod_set_localaddr(nu->nsiod, &ss, sslen);
       }
       if (o.ipoptionslen)
@@ -548,6 +556,14 @@
   if (nu->source_addr.ss_family != AF_UNSPEC) {
     nsock_iod_set_localaddr(nu->nsiod, &nu->source_addr, nu->source_addrlen);
   } else if (0 == o.SourceSockAddr(&ss, &sslen)) {
+    // Use the exact protocol-specific length.  Some platforms (e.g. FreeBSD)
+    // reject sizeof(sockaddr_storage) passed to bind() with EINVAL.
+    if (ss.ss_family == AF_INET)
+      sslen = sizeof(struct sockaddr_in);
+#if HAVE_IPV6
+    else if (ss.ss_family == AF_INET6)
+      sslen = sizeof(struct sockaddr_in6);
+#endif
     nsock_iod_set_localaddr(nu->nsiod, &ss, sslen);
   }
   if (o.ipoptionslen)
