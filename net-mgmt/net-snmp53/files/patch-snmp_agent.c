--- agent/snmp_agent.c.orig	Tue Mar 22 11:11:51 2005
+++ agent/snmp_agent.c	Tue Mar 22 11:12:29 2005
@@ -825,6 +825,7 @@
             return 0;
         }
     } else {
+	SNMP_FREE(addr_string);
         if (hosts_ctl("snmpd", STRING_UNKNOWN, STRING_UNKNOWN, STRING_UNKNOWN)){
             snmp_log(allow_severity, "Connection from <UNKNOWN>\n");
             addr_string = strdup("<UNKNOWN>");
