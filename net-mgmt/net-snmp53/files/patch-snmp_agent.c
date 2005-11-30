--- agent/snmp_agent.c.orig	Thu Mar 17 17:17:43 2005
+++ agent/snmp_agent.c	Wed Nov 30 12:23:41 2005
@@ -839,6 +839,7 @@
             ;
         else if (hosts_ctl("snmpd", STRING_UNKNOWN, STRING_UNKNOWN, STRING_UNKNOWN)){
             snmp_log(allow_severity, "Connection from <UNKNOWN> (%s)\n", addr_string);
+            SNMP_FREE(addr_string);
             addr_string = strdup("<UNKNOWN>");
         } else {
             snmp_log(deny_severity, "Connection from <UNKNOWN> (%s) REFUSED\n", addr_string);
