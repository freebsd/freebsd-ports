--- src/zabbix_agent/zabbix_agentd.c.orig	2016-09-01 07:20:23 UTC
+++ src/zabbix_agent/zabbix_agentd.c
@@ -249,7 +249,7 @@ static void	set_defaults()
 
 #ifdef USE_PID_FILE
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = "/tmp/zabbix_agentd.pid";
+		CONFIG_PID_FILE = "/var/run/zabbix/zabbix_agentd.pid";
 #endif
 
 }
