Index: agent/snmp_agent.c
diff -u -p agent/snmp_agent.c.orig agent/snmp_agent.c
--- agent/snmp_agent.c.orig	Thu Aug 16 22:31:40 2007
+++ agent/snmp_agent.c	Fri Jan 11 13:06:27 2008
@@ -819,7 +819,7 @@ netsnmp_agent_check_packet(netsnmp_sessi
     }
 #ifdef  USE_LIBWRAP
     /* Catch udp,udp6,tcp,tcp6 transports using "[" */
-    tcpudpaddr = strstr(addr_string, "[");
+    tcpudpaddr = strrchr(addr_string, '[');
     if ( tcpudpaddr != 0 ) {
         char sbuf[64];
         char *xp;
