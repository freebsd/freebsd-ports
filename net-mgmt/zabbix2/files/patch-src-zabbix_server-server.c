--- src/zabbix_server/server.c.orig	Tue Jul 25 17:53:16 2006
+++ src/zabbix_server/server.c	Tue Jul 25 17:53:22 2006
@@ -361,7 +361,7 @@
 
 	if(CONFIG_FILE == NULL)
 	{
-		CONFIG_FILE=strdup("/etc/zabbix/zabbix_server.conf");
+		CONFIG_FILE=strdup("%PREFIX%/etc/zabbix/zabbix_server.conf");
 	}
 
 	parse_cfg_file(CONFIG_FILE,cfg);
@@ -381,7 +381,7 @@
 	}
 	if(CONFIG_FPING_LOCATION == NULL)
 	{
-		CONFIG_FPING_LOCATION=strdup("/usr/sbin/fping");
+		CONFIG_FPING_LOCATION=strdup("%LOCALBASE%/fping");
 	}
 
 }
