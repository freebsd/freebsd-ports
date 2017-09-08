--- src/zabbix_agent/zabbix_agentd.c.orig	2016-09-25 16:15:50 UTC
+++ src/zabbix_agent/zabbix_agentd.c
@@ -522,7 +522,7 @@ static void	set_defaults(void)
 		CONFIG_LOAD_MODULE_PATH = zbx_strdup(CONFIG_LOAD_MODULE_PATH, LIBDIR "/modules");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = "/tmp/zabbix_agentd.pid";
+		CONFIG_PID_FILE = "/var/run/zabbix/zabbix_agentd.pid";
 #endif
 	if (NULL == CONFIG_LOG_TYPE_STR)
 		CONFIG_LOG_TYPE_STR = zbx_strdup(CONFIG_LOG_TYPE_STR, ZBX_OPTION_LOGTYPE_FILE);
