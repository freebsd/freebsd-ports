--- runtime/nsd_ptcp.c.orig	2017-04-28 07:04:53 UTC
+++ runtime/nsd_ptcp.c
@@ -665,7 +665,11 @@ EnableKeepAlive(nsd_t *pNsd)
 	if(pThis->iKeepAliveProbes > 0) {
 		optval = pThis->iKeepAliveProbes;
 		optlen = sizeof(optval);
+#if defined(SOL_TCP)
 		ret = setsockopt(pThis->sock, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+#else
+		ret = setsockopt(pThis->sock, SOL_SOCKET, TCP_KEEPCNT, &optval, optlen);
+#endif
 	} else {
 		ret = 0;
 	}
@@ -680,7 +684,11 @@ EnableKeepAlive(nsd_t *pNsd)
 	if(pThis->iKeepAliveTime > 0) {
 		optval = pThis->iKeepAliveTime;
 		optlen = sizeof(optval);
+#if defined(SOL_TCP)
 		ret = setsockopt(pThis->sock, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+#else
+		ret = setsockopt(pThis->sock, SOL_SOCKET, TCP_KEEPIDLE, &optval, optlen);
+#endif
 	} else {
 		ret = 0;
 	}
@@ -695,7 +703,11 @@ EnableKeepAlive(nsd_t *pNsd)
 	if(pThis->iKeepAliveIntvl > 0) {
 		optval = pThis->iKeepAliveIntvl;
 		optlen = sizeof(optval);
+#if defined(SOL_TCP)
 		ret = setsockopt(pThis->sock, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+#else
+		ret = setsockopt(pThis->sock, SOL_SOCKET, TCP_KEEPINTVL, &optval, optlen);
+#endif
 	} else {
 		ret = 0;
 	}
