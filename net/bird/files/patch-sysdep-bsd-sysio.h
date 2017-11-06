diff --git sysdep/bsd/sysio.h sysdep/bsd/sysio.h
index 2610a47..9b10e6e 100644
--- sysdep/bsd/sysio.h
+++ sysdep/bsd/sysio.h
@@ -9,6 +9,7 @@
 #include <net/if_dl.h>
 #include <netinet/in_systm.h> // Workaround for some BSDs
 #include <netinet/ip.h>
+#include <sys/param.h>
 
 
 #ifdef __NetBSD__
@@ -179,8 +180,8 @@ sk_prepare_ip_header(sock *s, void *hdr, int dlen)
   ip->ip_src = ipa_to_in4(s->saddr);
   ip->ip_dst = ipa_to_in4(s->daddr);
 
-#ifdef __OpenBSD__
-  /* OpenBSD expects ip_len in network order, other BSDs expect host order */
+#if (defined __OpenBSD__) || (defined __DragonFly__) || (defined __FreeBSD__ && (__FreeBSD_version >= 1100030))
+  /* Different BSDs have different expectations of ip_len endianity */
   ip->ip_len = htons(ip->ip_len);
 #endif
 }
