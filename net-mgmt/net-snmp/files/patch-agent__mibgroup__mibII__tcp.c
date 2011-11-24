--- ./agent/mibgroup/mibII/tcp.c.orig	2011-11-24 07:57:25.000000000 -0500
+++ ./agent/mibgroup/mibII/tcp.c	2011-11-24 07:57:51.000000000 -0500
@@ -92,7 +92,7 @@
 int  hz = 1000;
 #endif
 
-#ifdef NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS
+#ifndef NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS
 extern int TCP_Count_Connections( void );
 #endif /* NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS */
         /*********************
@@ -373,7 +373,7 @@
 #ifdef NETSNMP_FEATURE_CHECKING
         netsnmp_feature_want(tcp_count_connections)
 #endif
-#ifdef NETSNMP_FEATURE_HAS_TCP_COUNT_CONNECTIONS
+#ifndef NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS
         ret_value = TCP_Count_Connections();
 #else /*  NETSNMP_FEATURE_HAS_TCP_COUNT_CONNECTIONS */
         ret_value = 0;
