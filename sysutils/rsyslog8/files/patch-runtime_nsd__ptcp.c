--- runtime/nsd_ptcp.c.orig	2016-11-06 16:32:01 UTC
+++ runtime/nsd_ptcp.c
@@ -656,7 +656,11 @@ EnableKeepAlive(nsd_t *pNsd)
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
@@ -671,7 +675,11 @@ EnableKeepAlive(nsd_t *pNsd)
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
@@ -686,7 +694,11 @@ EnableKeepAlive(nsd_t *pNsd)
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
