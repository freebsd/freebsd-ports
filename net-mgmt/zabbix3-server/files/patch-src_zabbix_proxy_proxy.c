--- src/zabbix_proxy/proxy.c.orig	2016-04-20 12:51:20.000000000 +0300
+++ src/zabbix_proxy/proxy.c	2016-05-13 14:46:44.193569184 +0300
@@ -389,7 +389,7 @@
 		CONFIG_SNMPTRAP_FILE = zbx_strdup(CONFIG_SNMPTRAP_FILE, "/tmp/zabbix_traps.tmp");
 
 	if (NULL == CONFIG_PID_FILE)
-		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/tmp/zabbix_proxy.pid");
+		CONFIG_PID_FILE = zbx_strdup(CONFIG_PID_FILE, "/var/run/zabbix/zabbix_proxy.pid");
 
 	if (NULL == CONFIG_TMPDIR)
 		CONFIG_TMPDIR = zbx_strdup(CONFIG_TMPDIR, "/tmp");
