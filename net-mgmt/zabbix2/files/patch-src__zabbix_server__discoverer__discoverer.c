--- src/zabbix_server/discoverer/discoverer.c	(revision 5170)
+++ src/zabbix_server/discoverer/discoverer.c	(revision 5173)
@@ -723,7 +723,7 @@
 
 	assert(rule);
 
-	zabbix_log(LOG_LEVEL_DEBUG, "In process_rule(name:%s,range:%s)",
+	zabbix_log(LOG_LEVEL_DEBUG, "In process_rule() [name:%s] [range:%s]",
 		rule->name,
 		rule->iprange);
 
@@ -805,7 +805,7 @@
 
 		if( first < 0 || last < 0 )
 		{
-			zabbix_log(LOG_LEVEL_WARNING, "Wrong format of IP range [%s]",
+			zabbix_log(LOG_LEVEL_WARNING, "Discovery: Wrong format of IP range [%s]",
 				rule->iprange);
 			continue;
 		}
@@ -818,7 +818,7 @@
 				case 1 : zbx_snprintf(ip, sizeof(ip), "%s%x", prefix, i); break;
 			}
 
-			zabbix_log(LOG_LEVEL_DEBUG, "Discovery: process_rule() [first %d] [last %d] [IP %s]", prefix, first, last, ip);
+			zabbix_log(LOG_LEVEL_DEBUG, "Discovery: process_rule() [IP:%s]", ip);
 
 			result = DBselect("select dcheckid,druleid,type,key_,snmp_community,ports from dchecks where druleid=" ZBX_FS_UI64,
 				rule->druleid);
