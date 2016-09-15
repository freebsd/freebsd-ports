--- src/zabbix_agent/zabbix_agentd.c.orig	2016-09-13 16:27:58 UTC
+++ src/zabbix_agent/zabbix_agentd.c
@@ -271,7 +271,7 @@ static void	set_defaults(void)
 
 #ifdef USE_PID_FILE
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = "/tmp/zabbix_agentd.pid";
+		CONFIG_PID_FILE = "/var/run/zabbix/zabbix_agentd.pid";
 #endif
 }
 
