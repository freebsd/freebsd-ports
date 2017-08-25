--- src/zabbix_server/server.c.orig	2016-09-25 16:17:40 UTC
+++ src/zabbix_server/server.c
@@ -376,7 +376,7 @@ static void	zbx_set_defaults(void)
 		CONFIG_SNMPTRAP_FILE = zbx_strdup(CONFIG_SNMPTRAP_FILE, "/tmp/zabbix_traps.tmp");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/tmp/zabbix_server.pid");
+		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/var/run/zabbix/zabbix_server.pid");
 
 	if (NULL == CONFIG_ALERT_SCRIPTS_PATH)
 		CONFIG_ALERT_SCRIPTS_PATH = zbx_strdup(CONFIG_ALERT_SCRIPTS_PATH, DATADIR "/zabbix/alertscripts");
