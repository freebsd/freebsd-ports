--- service_scan.cc.orig	2026-08-20 12:25:01.000000000 -0700
+++ service_scan.cc	2026-08-20 13:26:28.448487000 -0700
@@ -2137,6 +2137,14 @@
         fatal("Failed to allocate Nsock I/O descriptor in %s()", __func__);
       }
       if (0 == svc->target->SourceSockAddr(&ss, &ss_len)) {
+        // Use the exact protocol-specific length.  Some platforms (e.g. FreeBSD)
+        // reject sizeof(sockaddr_storage) passed to bind() with EINVAL.
+        if (ss.ss_family == AF_INET)
+          ss_len = sizeof(struct sockaddr_in);
+#if HAVE_IPV6
+        else if (ss.ss_family == AF_INET6)
+          ss_len = sizeof(struct sockaddr_in6);
+#endif
         nsock_iod_set_localaddr(svc->niod, &ss, ss_len);
       }
       if (o.ipoptionslen)
