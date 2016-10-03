--- src/zabbix_server/server.c.orig	2016-04-20 12:51:20.000000000 +0300
+++ src/zabbix_server/server.c	2016-05-13 14:20:17.603677788 +0300
@@ -369,7 +369,7 @@
 		CONFIG_SNMPTRAP_FILE = zbx_strdup(CONFIG_SNMPTRAP_FILE, "/tmp/zabbix_traps.tmp");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/tmp/zabbix_server.pid");
+		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/var/run/zabbix/zabbix_server.pid");
 
 	if (NULL == CONFIG_ALERT_SCRIPTS_PATH)
 		CONFIG_ALERT_SCRIPTS_PATH = zbx_strdup(CONFIG_ALERT_SCRIPTS_PATH, DATADIR "/zabbix/alertscripts");
