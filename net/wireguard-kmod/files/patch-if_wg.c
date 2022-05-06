--- if_wg.c.orig	2021-11-05 14:40:17 UTC
+++ if_wg.c
@@ -377,7 +377,11 @@ static struct wg_packet *wg_queue_dequeue_parallel(str
 static int wg_queue_both(struct wg_queue *, struct wg_queue *, struct wg_packet *);
 static struct wg_packet *wg_queue_dequeue_serial(struct wg_queue *);
 static struct wg_packet *wg_queue_dequeue_parallel(struct wg_queue *);
+#if __FreeBSD_version >= 1400057
+static bool wg_input(struct mbuf *, int, struct inpcb *, const struct sockaddr *, void *);
+#else
 static void wg_input(struct mbuf *, int, struct inpcb *, const struct sockaddr *, void *);
+#endif
 static void wg_peer_send_staged(struct wg_peer *);
 static int wg_clone_create(struct if_clone *, int, caddr_t);
 static void wg_qflush(struct ifnet *);
@@ -1946,9 +1950,15 @@ wg_queue_dequeue_parallel(struct wg_queue *parallel)
 	return (pkt);
 }
 
+#if __FreeBSD_version >= 1400057
+static bool
+wg_input(struct mbuf *m, int offset, struct inpcb *inpcb,
+    const struct sockaddr *sa, void *_sc)
+#else
 static void
 wg_input(struct mbuf *m, int offset, struct inpcb *inpcb,
     const struct sockaddr *sa, void *_sc)
+#endif
 {
 	const struct sockaddr_in	*sin;
 	const struct sockaddr_in6	*sin6;
@@ -1965,7 +1975,11 @@ wg_input(struct mbuf *m, int offset, struct inpcb *inp
 	m = m_unshare(m, M_NOWAIT);
 	if (!m) {
 		if_inc_counter(sc->sc_ifp, IFCOUNTER_IQDROPS, 1);
+#if __FreeBSD_version >= 1400057
+		return true;
+#else
 		return;
+#endif
 	}
 
 	/* Caller provided us with `sa`, no need for this header. */
@@ -1974,13 +1988,21 @@ wg_input(struct mbuf *m, int offset, struct inpcb *inp
 	/* Pullup enough to read packet type */
 	if ((m = m_pullup(m, sizeof(uint32_t))) == NULL) {
 		if_inc_counter(sc->sc_ifp, IFCOUNTER_IQDROPS, 1);
+#if __FreeBSD_version >= 1400057
+		return true;
+#else
 		return;
+#endif
 	}
 
 	if ((pkt = wg_packet_alloc(m)) == NULL) {
 		if_inc_counter(sc->sc_ifp, IFCOUNTER_IQDROPS, 1);
 		m_freem(m);
+#if __FreeBSD_version >= 1400057
+		return true;
+#else
 		return;
+#endif
 	}
 
 	/* Save send/recv address and port for later. */
@@ -2027,11 +2049,19 @@ wg_input(struct mbuf *m, int offset, struct inpcb *inp
 	} else {
 		goto error;
 	}
+#if __FreeBSD_version >= 1400057
+	return true;
+#else
 	return;
+#endif
 error:
 	if_inc_counter(sc->sc_ifp, IFCOUNTER_IERRORS, 1);
 	wg_packet_free(pkt);
+#if __FreeBSD_version >= 1400057
+	return true;
+#else
 	return;
+#endif
 }
 
 static void
