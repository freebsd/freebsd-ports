--- src/zabbix_proxy/proxy.c.orig	2016-09-01 07:20:44 UTC
+++ src/zabbix_proxy/proxy.c
@@ -238,7 +238,7 @@ static void	zbx_set_defaults()
 		CONFIG_SNMPTRAP_FILE = zbx_strdup(CONFIG_SNMPTRAP_FILE, "/tmp/zabbix_traps.tmp");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/tmp/zabbix_proxy.pid");
+		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/var/run/zabbix/zabbix_proxy.pid");
 
 	if (NULL == CONFIG_TMPDIR)
 		CONFIG_TMPDIR = zbx_strdup(CONFIG_TMPDIR, "/tmp");
