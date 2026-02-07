--- aoenet.c.orig	2006-05-25 16:10:11 UTC
+++ aoenet.c
@@ -75,13 +75,12 @@ static char *aoe_errlist[] =
 };
 
 #define NECODES (sizeof(aoe_errlist) /  sizeof(char *) - 1)
-#if (__FreeBSD_version < 600000)
-#define IFPADDR(ifp) (((struct arpcom *) (ifp))->ac_enaddr)
-#else
-#define IFPADDR(ifp) IFP2ENADDR(ifp) 
-#endif
+#include <net/if_dl.h>
+#define IFPADDR(ifp) IF_LLADDR(ifp)
 #define IFLISTSZ 1024
 
+#define	IFNET_FOREACH(v)	CK_STAILQ_FOREACH(v, &V_ifnet, if_link)
+
 static char aoe_iflist[IFLISTSZ];
 
 static int sysctl_aoe_iflist(SYSCTL_HANDLER_ARGS);
@@ -91,50 +90,7 @@ SYSCTL_OID(_net_aoe, OID_AUTO, iflist, CTLTYPE_STRING|
 	aoe_iflist, IFLISTSZ - 1, sysctl_aoe_iflist, "A", 
 	"Space separated list of interfaces valid for AoE"); 
 
-#if (__FreeBSD_version < 600000)
-/* FreeBSD 5.X doesn't include strspn()... */
-#include <sys/limits.h>
-#define IDX(c)  ((u_char)(c) / LONG_BIT)
-#define BIT(c)  ((u_long)1 << ((u_char)(c) % LONG_BIT))
- 
-static size_t
-strspn(const char *s, const char *charset)
-{
-       /*
-        * NB: idx and bit are temporaries whose use causes gcc 3.4.2 to
-        * generate better code.  Without them, gcc gets a little confused.
-        */
-       const char *s1;
-       u_long bit;
-       u_long tbl[(UCHAR_MAX + 1) / LONG_BIT];
-       int idx;
- 
-       if(*s == '\0')
-               return (0);
- 
-#if LONG_BIT == 64      /* always better to unroll on 64-bit architectures */
-       tbl[3] = tbl[2] = tbl[1] = tbl[0] = 0;
-#else
-       for (idx = 0; idx < sizeof(tbl) / sizeof(tbl[0]); idx++)
-               tbl[idx] = 0;
-#endif
-       for (; *charset != '\0'; charset++) {
-               idx = IDX(*charset);
-               bit = BIT(*charset);
-               tbl[idx] |= bit;
-       }
 
-       for(s1 = s; ; s1++) {
-               idx = IDX(*s1);
-               bit = BIT(*s1);
-               if ((tbl[idx] & bit) == 0)
-                       break;
-       }
-       return (s1 - s);
-}
-#endif /* __FreeBSD_version < 600000 */
- 
-
 /* aoe_strcspn -- span the complement of a string */
 static size_t
 aoe_strcspn(const char *s, const char *reject)
@@ -160,7 +116,7 @@ is_aoe_netif(struct ifnet *ifp)
         register char *p, *q;
         register int len;
 
-        switch (ifp->if_data.ifi_type) {
+        switch (ifp->if_type) {
         default:
                 return (FALSE);
         case IFT_ETHER:
@@ -191,7 +147,7 @@ is_aoe_netif(struct ifnet *ifp)
  * a dummy "free" function for mbuf ext buffer 
  */
 static void
-nilfn(void *a, void *b)
+nilfn(struct mbuf *m)
 {
 }
 
@@ -201,7 +157,7 @@ frame_mbufinit(struct frame *f)
 {
         struct mbuf *m;
 
-	if ((m = m_gethdr(M_DONTWAIT, MT_DATA)) == NULL)
+	if ((m = m_gethdr(M_NOWAIT, MT_DATA)) == NULL)
 		return (NULL);
 	m->m_len = AOEHDRSZ;
 	m->m_pkthdr.len = f->f_mlen;
@@ -215,14 +171,15 @@ frame_mbufinit(struct frame *f)
                 u_int len;
 
                 len = f->f_mlen - AOEHDRSZ;
-		if ((m1 = m_get(M_DONTWAIT, MT_DATA)) == NULL) {
+		if ((m1 = m_get(M_NOWAIT, MT_DATA)) == NULL) {
 			m_freem(m);
 			return (NULL);
 		}
 		m->m_next = m1;
 
-		m1->m_ext.ref_cnt = NULL;
+		m1->m_ext.ext_cnt = NULL;
 		MEXTADD(m1, f->f_data, len, nilfn, 
+			f->f_data,
 			NULL, 0, EXT_NET_DRV);
 		m1->m_len = len;
 		m1->m_next = NULL;
@@ -272,11 +229,11 @@ aoenet_xmitbcast(u_short aoemajor, u_char aoeminor)
 	h->ah_cmd = AOECMD_CFG;
 
 	IFNET_RLOCK();
-	TAILQ_FOREACH(ifp, &ifnet, if_link) {
+	IFNET_FOREACH(ifp) {
 		if (!is_aoe_netif(ifp))
 			continue;
 		memcpy(h->ah_src, IFPADDR(ifp), sizeof(h->ah_src));
-		m = m_copypacket(m0, M_DONTWAIT);
+		m = m_copypacket(m0, M_NOWAIT);
 		if (m == NULL) {
 			IPRINTK("m_copypacket failure\n");
 			continue;
@@ -298,7 +255,7 @@ u_int
 aoenet_maxsize(struct ifnet *ifp)
 {
 	/* max payload size of packet based on interface mtu setting */
-	return ((ifp->if_data.ifi_mtu - AOEHDRSZ) & ~(DEV_BSIZE - 1));
+	return ((ifp->if_mtu - AOEHDRSZ) & ~(DEV_BSIZE - 1));
 }
 
 
@@ -362,7 +319,7 @@ aoe_ether_input(struct ifnet *ifp, struct mbuf *m)
          */
         if ((m->m_flags & M_PKTHDR) == 0) {
                 if_printf(ifp, "discard frame w/o packet header\n");
-                ifp->if_ierrors++;
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
                 m_freem(m);
                 return;
 	}
@@ -371,7 +328,7 @@ aoe_ether_input(struct ifnet *ifp, struct mbuf *m)
                 if_printf(ifp, "discard frame w/o leading ethernet "
                                 "header (len %u pkt len %u)\n",
                                 m->m_len, m->m_pkthdr.len);
-                ifp->if_ierrors++;
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
                 m_freem(m);
                 return;
         }
@@ -384,17 +341,17 @@ aoe_ether_input(struct ifnet *ifp, struct mbuf *m)
         if (m->m_pkthdr.len >
             ETHER_MAX_FRAME(ifp, etype, m->m_flags & M_HASFCS)) {
                 if_printf(ifp, "discard oversize frame "
-                                "(ether type %x flags %x len %u > max %lu)\n",
+                                "(ether type %x flags %x len %u > max %u)\n",
                                 etype, m->m_flags, m->m_pkthdr.len,
-                                ETHER_MAX_FRAME(ifp, etype,
+                                (int) ETHER_MAX_FRAME(ifp, etype,
                                                 m->m_flags & M_HASFCS));
-                ifp->if_ierrors++;
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
                 m_freem(m);
                 return;
         }
         if (m->m_pkthdr.rcvif == NULL) {
                 if_printf(ifp, "discard frame w/o interface pointer\n");
-                ifp->if_ierrors++;
+		if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
                 m_freem(m);
                 return;
 	}
@@ -417,7 +374,7 @@ aoe_ether_input(struct ifnet *ifp, struct mbuf *m)
                 m->m_flags &= ~M_HASFCS;
         }
 
-        ifp->if_ibytes += m->m_pkthdr.len;
+	if_inc_counter(ifp, IFCOUNTER_IBYTES, m->m_pkthdr.len);
 
         if (ETHER_IS_MULTICAST(eh->ether_dhost)) {
                 if (bcmp(etherbroadcastaddr, eh->ether_dhost,
@@ -427,7 +384,7 @@ aoe_ether_input(struct ifnet *ifp, struct mbuf *m)
                         m->m_flags |= M_MCAST;
         }
         if (m->m_flags & (M_BCAST|M_MCAST))
-                ifp->if_imcasts++;
+		if_inc_counter(ifp, IFCOUNTER_IMCASTS, 1);
 
 	aoeintr(m); 
 	/* netisr_dispatch(NETISR_AOE, m); */
@@ -446,7 +403,7 @@ sysctl_aoe_iflist(SYSCTL_HANDLER_ARGS)
 
 #ifdef FORCE_NETWORK_HOOK
 	IFNET_RLOCK();
-	TAILQ_FOREACH(ifp, &ifnet, if_link) {
+	IFNET_FOREACH(ifp) {
 		if (!is_aoe_netif(ifp)) {
 			if (ifp->if_input == aoe_ether_input)
 				ifp->if_input = old_ether_input;
@@ -471,8 +428,8 @@ aoenet_init(void)
 	struct ifnet *ifp;
 
 	IFNET_RLOCK();
-	TAILQ_FOREACH(ifp, &ifnet, if_link) {
-        	switch (ifp->if_data.ifi_type) {
+	IFNET_FOREACH(ifp) {
+        	switch (ifp->if_type) {
         	case IFT_ETHER:
         	case IFT_FASTETHER:
         	case IFT_GIGABITETHERNET:
@@ -500,8 +457,8 @@ aoenet_exit(void)
 	struct ifnet *ifp;
 
 	IFNET_RLOCK();
-	TAILQ_FOREACH(ifp, &ifnet, if_link) {
-        	switch (ifp->if_data.ifi_type) {
+	IFNET_FOREACH(ifp) {
+        	switch (ifp->if_type) {
         	case IFT_ETHER:
         	case IFT_FASTETHER:
         	case IFT_GIGABITETHERNET:
