--- src/zabbix_agent/zabbix_agentd.c.orig	Tue Jul 25 19:51:53 2006
+++ src/zabbix_agent/zabbix_agentd.c	Tue Jul 25 19:52:01 2006
@@ -298,7 +298,7 @@
 	
 	if(CONFIG_FILE == NULL)
 	{
-		CONFIG_FILE = strdup("/etc/zabbix/zabbix_agentd.conf");
+		CONFIG_FILE = strdup("%PREFIX%/etc/zabbix/zabbix_agentd.conf");
 	}
 
 	parse_cfg_file(CONFIG_FILE,cfg);
