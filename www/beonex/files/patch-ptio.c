Don't use mapped IPv6 address when connecting [in] IPv4 node.

author:  Hajimu UMEMOTO (FreeBSD.org login "ume")

Index: nsprpub/pr/src/pthreads/ptio.c
diff -u nsprpub/pr/src/pthreads/ptio.c.orig nsprpub/pr/src/pthreads/ptio.c
--- nsprpub/pr/src/pthreads/ptio.c.orig	Fri Apr 12 03:14:39 2002
+++ nsprpub/pr/src/pthreads/ptio.c	Tue Jul 30 18:52:11 2002
@@ -3414,6 +3414,17 @@
     if (osfd == -1) pt_MapError(_PR_MD_MAP_SOCKET_ERROR, errno);
     else
     {
+#if (defined(_PR_INET6_PROBE) || defined(_PR_INET6)) && \
+	defined(__FreeBSD__) && defined(IPV6_V6ONLY)
+		if (domain == PR_AF_INET6) {
+			int opt = 0;
+			if (setsockopt(osfd, IPPROTO_IPV6, IPV6_V6ONLY,
+                           &opt, sizeof(opt))) {
+				close(osfd);
+				return NULL;
+			}
+		}
+#endif
         fd = pt_SetMethods(osfd, ftype, PR_FALSE, PR_FALSE);
         if (fd == NULL) close(osfd);
     }
