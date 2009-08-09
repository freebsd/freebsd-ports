--- vrrp_network.c.orig	2009-08-09 11:49:22.000000000 +0400
+++ vrrp_network.c	2009-08-09 11:50:47.000000000 +0400
@@ -36,6 +36,8 @@
 #include "vrrp_network.h"
 #include "vrrp_ah.h"
 
+#include <sys/param.h>
+
 u_short         ip_id;
 
 /* Initialisation pour l'identification IP */
@@ -310,7 +312,10 @@
 	rtm.rtm_type = RTM_DELETE;
 	rtm.rtm_version = RTM_VERSION;
 #ifdef __FreeBSD__
-	rtm.rtm_flags = RTF_UP | RTF_HOST | RTF_LOCAL | RTF_WASCLONED;
+	rtm.rtm_flags = RTF_UP | RTF_HOST | RTF_LOCAL;
+#if __FreeBSD_version < 800059
+	rtm.rtm_flags |= RTF_WASCLONED;
+#endif
 #endif
 #ifdef __NetBSD__
 	rtm.rtm_flags = RTF_UP | RTF_HOST | RTF_CLONED;
