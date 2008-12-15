--- lib/sockopt.c.orig	2008-09-05 18:27:26.000000000 +0400
+++ lib/sockopt.c	2008-12-15 19:36:40.000000000 +0300
@@ -319,6 +319,32 @@
 
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
@@ -494,70 +520,3 @@
 
   iph->ip_id = ntohs(iph->ip_id);
 }
-
-int
-sockopt_tcp_signature (int sock, union sockunion *su, const char *password)
-{
-#if HAVE_DECL_TCP_MD5SIG
-  int ret;
-#ifndef GNU_LINUX
-  /*
-   * XXX Need to do PF_KEY operation here to add/remove an SA entry,
-   * and add/remove an SP entry for this peer's packet flows also.
-   */
-  int md5sig = password && *password ? 1 : 0;
-#else
-  int keylen = password ? strlen (password) : 0;
-  struct tcp_md5sig md5sig;
-  union sockunion *su2, *susock;
-  
-  /* Figure out whether the socket and the sockunion are the same family..
-   * adding AF_INET to AF_INET6 needs to be v4 mapped, you'd think..
-   */
-  if (!(susock = sockunion_getsockname (sock)))
-    return -1;
-  
-  if (susock->sa.sa_family == su->sa.sa_family)
-    su2 = su;
-  else
-    {
-      /* oops.. */
-      su2 = susock;
-      
-      if (su2->sa.sa_family == AF_INET)
-        {
-          sockunion_free (susock);
-          return -1;
-        };
-      
-      /* If this does not work, then all users of this sockopt will need to
-       * differentiate between IPv4 and IPv6, and keep seperate sockets for
-       * each. 
-       *
-       * Sadly, it doesn't seem to work at present. It's unknown whether
-       * this is a bug or not.
-       */
-      if (su2->sa.sa_family == AF_INET6
-          && su->sa.sa_family == AF_INET)
-        {
-           su2->sin6.sin6_family = AF_INET6;
-           /* V4Map the address */
-           memset (&su2->sin6.sin6_addr, 0, sizeof (struct in6_addr));
-           su2->sin6.sin6_addr.s6_addr32[2] = htonl(0xffff);
-           memcpy (&su2->sin6.sin6_addr.s6_addr32[3], &su->sin.sin_addr, 4);
-        }
-    }
-  
-  memset (&md5sig, 0, sizeof (md5sig));
-  memcpy (&md5sig.tcpm_addr, su2, sizeof (*su2));
-  md5sig.tcpm_keylen = keylen;
-  if (keylen)
-    memcpy (md5sig.tcpm_key, password, keylen);
-  sockunion_free (susock);
-#endif /* GNU_LINUX */
-  ret = setsockopt (sock, IPPROTO_TCP, TCP_MD5SIG, &md5sig, sizeof md5sig);
-  return ret;
-#else /* HAVE_TCP_MD5SIG */
-  return -2;
-#endif /* HAVE_TCP_MD5SIG */
-}
