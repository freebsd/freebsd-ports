
$FreeBSD$

--- alclib/linux_ssm.h.orig	Fri Jul 30 14:15:54 2004
+++ alclib/linux_ssm.h	Mon Aug  2 11:50:48 2004
@@ -33,12 +33,12 @@
 
 struct ip_mreq_source {
   struct in_addr imr_multiaddr;  /* IP address of group */
-  struct in_addr imr_interface;  /* IP address of interface */
   struct in_addr imr_sourceaddr; /* IP address of source */
+  struct in_addr imr_interface;  /* IP address of interface */
 };
 
-#define IP_ADD_SOURCE_MEMBERSHIP        39
-#define IP_DROP_SOURCE_MEMBERSHIP       40
+#define IP_ADD_SOURCE_MEMBERSHIP        25
+#define IP_DROP_SOURCE_MEMBERSHIP       26
 
 #endif
 
@@ -54,8 +54,8 @@
       struct sockaddr_storage gsr_source;    /* source address */
    };
 
-#define MCAST_JOIN_SOURCE_GROUP  46
-#define MCAST_LEAVE_SOURCE_GROUP  47
+#define MCAST_JOIN_SOURCE_GROUP  74
+#define MCAST_LEAVE_SOURCE_GROUP  75
 
 #endif
 
