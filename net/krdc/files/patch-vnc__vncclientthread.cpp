Only use TCP_KEEPIDLE, TCP_KEEPINTVL and TCP_KEEPCNT if they exist.

These options are present only in FreeBSD 9+, so we need this patch to maintain
compatibility with FreeBSD 8.

Not worth upstreaming, as OS X, Linux, NetBSD, OpenBSD and DragonFlyBSD have
had these options for much longer than us.
--- vnc/vncclientthread.cpp
+++ vnc/vncclientthread.cpp
@@ -606,23 +606,30 @@ void VncClientThread::clientSetKeepalive()
         return;
     }
 
+#ifdef TCP_KEEPIDLE
     optval = m_keepalive.intervalSeconds;
     if (setsockopt(cl->sock, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen) < 0) {
         kError(5011) << "setsockopt(TCP_KEEPIDLE)" << strerror(errno);
         return;
     }
+#endif
 
+#ifdef TCP_KEEPINTVL
     optval = m_keepalive.intervalSeconds;
     if (setsockopt(cl->sock, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen) < 0) {
         kError(5011) << "setsockopt(TCP_KEEPINTVL)" << strerror(errno);
         return;
     }
+#endif
 
+#ifdef TCP_KEEPCNT
     optval = m_keepalive.failedProbes;
     if(setsockopt(cl->sock, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen) < 0) {
         kError(5011) << "setsockopt(TCP_KEEPCNT)" << strerror(errno);
         return;
     }
+#endif
+
     m_keepalive.set = true;
     kDebug(5011) << "TCP keepalive set";
 }
