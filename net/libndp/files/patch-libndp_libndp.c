--- libndp/libndp.c.orig	2021-05-20 09:39:25 UTC
+++ libndp/libndp.c
@@ -35,6 +35,17 @@
 #include <net/if.h>
 #include <sys/ioctl.h>
 
+#ifdef __FreeBSD__
+#define s6_addr8  __u6_addr.__u6_addr8
+#define s6_addr16 __u6_addr.__u6_addr16
+#define s6_addr32 __u6_addr.__u6_addr32
+#define SIOCGIFHWADDR			SIOCGIFMAC
+#define ND_RA_FLAG_HOME_AGENT	ND_RA_FLAG_HA
+#define ND_OPT_PI_FLAG_RADDR	0x20
+#define ifr_hwaddr				ifr_addr
+#define ETH_ALEN				6
+#endif
+
 #include "ndp_private.h"
 #include "list.h"
 
@@ -209,7 +220,7 @@ resend:
 	memcpy(&sin6.sin6_addr, addr, sizeof(sin6.sin6_addr));
 	sin6.sin6_scope_id = ifindex;
 resend:
-	ret = sendto(sockfd, buf, buflen, flags, &sin6, sizeof(sin6));
+	ret = sendto(sockfd, buf, buflen, flags, (struct sockaddr*)&sin6, sizeof(sin6));
 	if (ret == -1) {
 		switch(errno) {
 		case EINTR:
