--- aoenet.c.orig	2006-05-25 23:10:11.000000000 +0700
+++ aoenet.c	2014-09-01 01:54:47.000000000 +0700
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
 
@@ -190,10 +193,24 @@
 /* 
  * a dummy "free" function for mbuf ext buffer 
  */
+#if __FreeBSD_version >= 1000050
+#if __FreeBSD_version >= 1100028
+static void
+#else
+static int
+#endif
+nilfn(struct mbuf *m, void *a, void *b)
+{
+#if __FreeBSD_version < 1100028
+	return EXT_FREE_OK;
+#endif
+}
+#else
 static void
 nilfn(void *a, void *b)
 {
 }
+#endif
 
 /* Create a mbuf chain and point to our data section(s). */
 static struct mbuf *
@@ -201,7 +218,7 @@
 {
         struct mbuf *m;
 
-	if ((m = m_gethdr(M_DONTWAIT, MT_DATA)) == NULL)
+	if ((m = m_gethdr(M_NOWAIT, MT_DATA)) == NULL)
 		return (NULL);
 	m->m_len = AOEHDRSZ;
 	m->m_pkthdr.len = f->f_mlen;
@@ -215,14 +232,21 @@
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
@@ -276,7 +300,7 @@
 		if (!is_aoe_netif(ifp))
 			continue;
 		memcpy(h->ah_src, IFPADDR(ifp), sizeof(h->ah_src));
-		m = m_copypacket(m0, M_DONTWAIT);
+		m = m_copypacket(m0, M_NOWAIT);
 		if (m == NULL) {
 			IPRINTK("m_copypacket failure\n");
 			continue;
@@ -384,9 +408,9 @@
         if (m->m_pkthdr.len >
             ETHER_MAX_FRAME(ifp, etype, m->m_flags & M_HASFCS)) {
                 if_printf(ifp, "discard oversize frame "
-                                "(ether type %x flags %x len %u > max %lu)\n",
+                                "(ether type %x flags %x len %u > max %u)\n",
                                 etype, m->m_flags, m->m_pkthdr.len,
-                                ETHER_MAX_FRAME(ifp, etype,
+                                (int) ETHER_MAX_FRAME(ifp, etype,
                                                 m->m_flags & M_HASFCS));
                 ifp->if_ierrors++;
                 m_freem(m);
