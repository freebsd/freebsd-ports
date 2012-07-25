--- defs.h.orig	2012-07-23 13:50:47.000000000 +0100
+++ defs.h	2012-07-23 13:35:04.000000000 +0100
@@ -262,7 +262,7 @@
 
 #ifndef IGMP_MEMBERSHIP_QUERY
 #define IGMP_MEMBERSHIP_QUERY		IGMP_HOST_MEMBERSHIP_QUERY
-#if !(defined(NetBSD))
+#if !(defined(NetBSD)) && !(defined(FreeBSD))
 #define IGMP_V1_MEMBERSHIP_REPORT	IGMP_HOST_MEMBERSHIP_REPORT
 #define IGMP_V2_MEMBERSHIP_REPORT	IGMP_HOST_NEW_MEMBERSHIP_REPORT
 #else
@@ -272,7 +272,7 @@
 #define IGMP_V2_LEAVE_GROUP		IGMP_HOST_LEAVE_MESSAGE
 #endif
 
-#if defined(NetBSD)
+#if defined(NetBSD) || defined(FreeBSD)
 #define IGMP_MTRACE_RESP                IGMP_MTRACE_REPLY
 #define IGMP_MTRACE                     IGMP_MTRACE_QUERY
 #endif
