--- defs.h.orig	1999-11-30 17:58:53 UTC
+++ defs.h
@@ -262,7 +262,7 @@ extern char *		sys_errlist[];
 
 #ifndef IGMP_MEMBERSHIP_QUERY
 #define IGMP_MEMBERSHIP_QUERY		IGMP_HOST_MEMBERSHIP_QUERY
-#if !(defined(NetBSD))
+#if !(defined(NetBSD)) && !(defined(FreeBSD))
 #define IGMP_V1_MEMBERSHIP_REPORT	IGMP_HOST_MEMBERSHIP_REPORT
 #define IGMP_V2_MEMBERSHIP_REPORT	IGMP_HOST_NEW_MEMBERSHIP_REPORT
 #else
@@ -272,7 +272,7 @@ extern char *		sys_errlist[];
 #define IGMP_V2_LEAVE_GROUP		IGMP_HOST_LEAVE_MESSAGE
 #endif
 
-#if defined(NetBSD)
+#if defined(NetBSD) || defined(FreeBSD)
 #define IGMP_MTRACE_RESP                IGMP_MTRACE_REPLY
 #define IGMP_MTRACE                     IGMP_MTRACE_QUERY
 #endif
