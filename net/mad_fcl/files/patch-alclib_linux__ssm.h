--- alclib/linux_ssm.h.orig	2016-03-08 14:49:04 UTC
+++ alclib/linux_ssm.h
@@ -54,12 +54,12 @@ extern "C" {
 
 struct ip_mreq_source {
   struct in_addr imr_multiaddr;  /**< IP address of group */
-  struct in_addr imr_interface;  /**< IP address of interface */
   struct in_addr imr_sourceaddr; /**< IP address of source */
+  struct in_addr imr_interface;  /**< IP address of interface */
 };
 
-#define IP_ADD_SOURCE_MEMBERSHIP        39
-#define IP_DROP_SOURCE_MEMBERSHIP       40
+#define IP_ADD_SOURCE_MEMBERSHIP        25
+#define IP_DROP_SOURCE_MEMBERSHIP       26
 
 #endif
 
@@ -84,8 +84,8 @@ struct group_source_req {
   struct sockaddr_storage gsr_source;	/**< source address */
 };
 
-#define MCAST_JOIN_SOURCE_GROUP		46
-#define MCAST_LEAVE_SOURCE_GROUP	47
+#define MCAST_JOIN_SOURCE_GROUP		74
+#define MCAST_LEAVE_SOURCE_GROUP	75
 
 #endif
 
