--- aoenet.c.orig	2006-05-25 16:10:11.000000000 +0000
+++ aoenet.c	2017-10-17 20:01:42.698938000 +0000
@@ -77,8 +77,11 @@
 #define NECODES (sizeof(aoe_errlist) /  sizeof(char *) - 1)
 #if (__FreeBSD_version < 600000)
 #define IFPADDR(ifp) (((struct arpcom *) (ifp))->ac_enaddr)
-#else
+#elif (__FreeBSD_version < 700000)
 #define IFPADDR(ifp) IFP2ENADDR(ifp) 
+#else
+#include <net/if_dl.h>
+#define IFPADDR(ifp) IF_LLADDR(ifp)
 #endif
 #define IFLISTSZ 1024
 
@@ -160,7 +163,11 @@
         register char *p, *q;
         register int len;
 
+#if __FreeBSD_version >= 1100030
+        switch (ifp->if_type) {
+#else
         switch (ifp->if_data.ifi_type) {
+#endif
         default:
                 return (FALSE);
         case IFT_ETHER:
@@ -190,10 +197,28 @@
 /* 
  * a dummy "free" function for mbuf ext buffer 
  */
+#if __FreeBSD_version >= 1200051
+static void
+nilfn(struct mbuf *m)
+{
+}
+#elif __FreeBSD_version >= 1100028
+static void
+nilfn(struct mbuf *m, void *a, void *b)
+{
+}
+#elif __FreeBSD_version >= 1000050
+static int
+nilfn(struct mbuf *m, void *a, void *b)
+{
+	return EXT_FREE_OK;
+}
+#else
 static void
 nilfn(void *a, void *b)
 {
 }
+#endif
 
 /* Create a mbuf chain and point to our data section(s). */
 static struct mbuf *
@@ -201,7 +226,7 @@
 {
         struct mbuf *m;
 
-	if ((m = m_gethdr(M_DONTWAIT, MT_DATA)) == NULL)
+	if ((m = m_gethdr(M_NOWAIT, MT_DATA)) == NULL)
 		return (NULL);
 	m->m_len = AOEHDRSZ;
 	m->m_pkthdr.len = f->f_mlen;
@@ -215,14 +240,21 @@
                 u_int len;
 
                 len = f->f_mlen - AOEHDRSZ;
-		if ((m1 = m_get(M_DONTWAIT, MT_DATA)) == NULL) {
+		if ((m1 = m_get(M_NOWAIT, MT_DATA)) == NULL) {
 			m_freem(m);
 			return (NULL);
 		}
 		m->m_next = m1;
 
+#if __FreeBSD_version >= 1100028
+		m1->m_ext.ext_cnt = NULL;
+#else
 		m1->m_ext.ref_cnt = NULL;
+#endif
 		MEXTADD(m1, f->f_data, len, nilfn, 
+#if (__FreeBSD_version >= 800000)
+			f->f_data,
+#endif
 			NULL, 0, EXT_NET_DRV);
 		m1->m_len = len;
 		m1->m_next = NULL;
@@ -276,7 +308,7 @@
 		if (!is_aoe_netif(ifp))
 			continue;
 		memcpy(h->ah_src, IFPADDR(ifp), sizeof(h->ah_src));
-		m = m_copypacket(m0, M_DONTWAIT);
+		m = m_copypacket(m0, M_NOWAIT);
 		if (m == NULL) {
 			IPRINTK("m_copypacket failure\n");
 			continue;
@@ -298,7 +330,11 @@
 aoenet_maxsize(struct ifnet *ifp)
 {
 	/* max payload size of packet based on interface mtu setting */
+#if __FreeBSD_version >= 1100030
+	return ((ifp->if_mtu - AOEHDRSZ) & ~(DEV_BSIZE - 1));
+#else
 	return ((ifp->if_data.ifi_mtu - AOEHDRSZ) & ~(DEV_BSIZE - 1));
+#endif
 }
 
 
@@ -362,7 +398,11 @@
          */
         if ((m->m_flags & M_PKTHDR) == 0) {
                 if_printf(ifp, "discard frame w/o packet header\n");
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
                 ifp->if_ierrors++;
+#endif
                 m_freem(m);
                 return;
 	}
@@ -371,7 +411,11 @@
                 if_printf(ifp, "discard frame w/o leading ethernet "
                                 "header (len %u pkt len %u)\n",
                                 m->m_len, m->m_pkthdr.len);
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
                 ifp->if_ierrors++;
+#endif
                 m_freem(m);
                 return;
         }
@@ -384,17 +428,25 @@
         if (m->m_pkthdr.len >
             ETHER_MAX_FRAME(ifp, etype, m->m_flags & M_HASFCS)) {
                 if_printf(ifp, "discard oversize frame "
-                                "(ether type %x flags %x len %u > max %lu)\n",
+                                "(ether type %x flags %x len %u > max %u)\n",
                                 etype, m->m_flags, m->m_pkthdr.len,
-                                ETHER_MAX_FRAME(ifp, etype,
+                                (int) ETHER_MAX_FRAME(ifp, etype,
                                                 m->m_flags & M_HASFCS));
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
                 ifp->if_ierrors++;
+#endif
                 m_freem(m);
                 return;
         }
         if (m->m_pkthdr.rcvif == NULL) {
                 if_printf(ifp, "discard frame w/o interface pointer\n");
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
                 ifp->if_ierrors++;
+#endif
                 m_freem(m);
                 return;
 	}
@@ -417,7 +469,11 @@
                 m->m_flags &= ~M_HASFCS;
         }
 
+#if __FreeBSD_version >= 1100036
+	if_inc_counter(ifp, IFCOUNTER_IBYTES, m->m_pkthdr.len);
+#else
         ifp->if_ibytes += m->m_pkthdr.len;
+#endif
 
         if (ETHER_IS_MULTICAST(eh->ether_dhost)) {
                 if (bcmp(etherbroadcastaddr, eh->ether_dhost,
@@ -427,7 +483,11 @@
                         m->m_flags |= M_MCAST;
         }
         if (m->m_flags & (M_BCAST|M_MCAST))
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_IMCASTS, 1);
+#else
                 ifp->if_imcasts++;
+#endif
 
 	aoeintr(m); 
 	/* netisr_dispatch(NETISR_AOE, m); */
@@ -472,7 +532,11 @@
 
 	IFNET_RLOCK();
 	TAILQ_FOREACH(ifp, &ifnet, if_link) {
+#if __FreeBSD_version >= 1100030
+        	switch (ifp->if_type) {
+#else
         	switch (ifp->if_data.ifi_type) {
+#endif
         	case IFT_ETHER:
         	case IFT_FASTETHER:
         	case IFT_GIGABITETHERNET:
@@ -501,7 +565,11 @@
 
 	IFNET_RLOCK();
 	TAILQ_FOREACH(ifp, &ifnet, if_link) {
+#if __FreeBSD_version >= 1100030
+        	switch (ifp->if_type) {
+#else
         	switch (ifp->if_data.ifi_type) {
+#endif
         	case IFT_ETHER:
         	case IFT_FASTETHER:
         	case IFT_GIGABITETHERNET:
