--- auth-ip.c	Sun Sep 22 12:56:52 2002
+++ auth-ip.c	Wed Nov  6 02:39:28 2002
@@ -94,8 +94,8 @@
         if (NULL != (fp = fopen("./spread.access_ip", "r")) )
             Alarm( PRINT, "ip_init: using file: ./spread.access_ip\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_ip", "r")) )
-            Alarm( PRINT, "ip_init: using file: /etc/spread.access_ip\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_ip", "r")) )
+            Alarm( PRINT, "ip_init: using file: " SPREAD_ETCDIR "/spread.access_ip\n");
     if (fp == NULL)
     {
         Alarm( PRINT, "ip_init: IP access control file not found.\nIf you are using IP based access controls, please make sure the file exists.\n");
