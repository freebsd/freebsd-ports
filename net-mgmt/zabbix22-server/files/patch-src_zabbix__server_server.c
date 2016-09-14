--- src/zabbix_server/server.c.orig	2016-09-13 16:28:31 UTC
+++ src/zabbix_server/server.c
@@ -226,7 +226,7 @@ static void	zbx_set_defaults()
 		CONFIG_SNMPTRAP_FILE = zbx_strdup(CONFIG_SNMPTRAP_FILE, "/tmp/zabbix_traps.tmp");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/tmp/zabbix_server.pid");
+		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/var/run/zabbix/zabbix_server.pid");
 
 	if (NULL == CONFIG_ALERT_SCRIPTS_PATH)
 		CONFIG_ALERT_SCRIPTS_PATH = zbx_strdup(CONFIG_ALERT_SCRIPTS_PATH, DATADIR "/zabbix/alertscripts");
