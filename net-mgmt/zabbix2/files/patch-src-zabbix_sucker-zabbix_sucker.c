--- src/zabbix_sucker/zabbix_sucker.c.orig	Wed Jan 14 07:43:02 2004
+++ src/zabbix_sucker/zabbix_sucker.c	Wed Jan 14 07:43:21 2004
@@ -254,7 +254,7 @@
 	}
 	if(CONFIG_FPING_LOCATION == NULL)
 	{
-		CONFIG_FPING_LOCATION=strdup("/usr/sbin/fping");
+		CONFIG_FPING_LOCATION=strdup("%LOCALBASE%/sbin/fping");
 	}
 }

