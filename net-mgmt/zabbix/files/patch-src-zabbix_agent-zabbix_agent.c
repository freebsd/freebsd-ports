--- src/zabbix_agent/zabbix_agent.c.orig	Tue Jul 25 19:51:28 2006
+++ src/zabbix_agent/zabbix_agent.c	Tue Jul 25 19:51:42 2006
@@ -108,7 +108,7 @@
 
 	if(CONFIG_FILE == NULL)
 	{
-		CONFIG_FILE = strdup("/etc/zabbix/zabbix_agentd.conf");
+		CONFIG_FILE = strdup("%PREFIX%/etc/zabbix/zabbix_agentd.conf");
 	}
 	
 	parse_cfg_file(CONFIG_FILE,cfg);
