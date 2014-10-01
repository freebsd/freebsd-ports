--- sysdep/bsd/sysio.h	2014-07-10 01:40:13.000000000 +0400
+++ sysdep/bsd/sysio.h	2014-09-27 12:12:09.000000000 +0400
@@ -9,6 +9,9 @@
 #include <net/if_dl.h>
 #include <netinet/in_systm.h> // Workaround for some BSDs
 #include <netinet/ip.h>
+#ifdef __FreeBSD__
+#include <sys/param.h> // FreeBSD_version definition
+#endif
 
 
 #ifdef __NetBSD__
@@ -175,8 +178,8 @@
   ip->ip_src = ipa_to_in4(s->saddr);
   ip->ip_dst = ipa_to_in4(s->daddr);
 
-#ifdef __OpenBSD__
-  /* OpenBSD expects ip_len in network order, other BSDs expect host order */
+#if defined __OpenBSD__ || (defined __FreeBSD__ && (__FreeBSD_version >= 1100030))
+  /* OpenBSD and FreeBSD (since 11) expects ip_len in network order, other BSDs expect host order */
   ip->ip_len = htons(ip->ip_len);
 #endif
 }
