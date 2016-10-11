--- src/zabbix_agent/zabbix_agentd.c.orig	2016-05-13 14:37:25.696606000 +0300
+++ src/zabbix_agent/zabbix_agentd.c	2016-05-13 14:49:45.011554761 +0300
@@ -521,7 +521,7 @@
 		CONFIG_LOAD_MODULE_PATH = zbx_strdup(CONFIG_LOAD_MODULE_PATH, LIBDIR "/modules");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = "/tmp/zabbix_agentd.pid";
+		CONFIG_PID_FILE = "/var/run/zabbix/zabbix_agentd.pid";
 #endif
 	if (NULL == CONFIG_LOG_TYPE_STR)
 		CONFIG_LOG_TYPE_STR = zbx_strdup(CONFIG_LOG_TYPE_STR, ZBX_OPTION_LOGTYPE_FILE);
