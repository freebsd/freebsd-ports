--- agent/mibgroup/mibII/tcpTable.c.orig	Wed Jun  9 05:53:17 2004
+++ agent/mibgroup/mibII/tcpTable.c	Thu Jun 24 23:21:32 2004
@@ -275,6 +277,9 @@
 
 int
 TCP_Count_Connections( void ) {
+#if (defined(CAN_USE_SYSCTL) && defined(TCPCTL_PCBLIST))
+    tcpTable_load(NULL, NULL);
+#endif
     return tcp_estab;
 }
 
