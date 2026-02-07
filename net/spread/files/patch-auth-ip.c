--- auth-ip.c	Fri Mar  5 11:32:46 2004
+++ auth-ip.c	Thu Jul 15 21:38:09 2004
@@ -90,12 +90,9 @@
     /* load spread.access_ip file */
     if (NULL != (fp = fopen(file_name,"r")) )
         Alarmp( SPLOG_INFO, ACM, "ip_init: using file: %s\n", file_name);
-    if (fp == NULL) 
-        if (NULL != (fp = fopen("./spread.access_ip", "r")) )
-            Alarmp( SPLOG_INFO, ACM, "ip_init: using file: ./spread.access_ip\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_ip", "r")) )
-            Alarmp( SPLOG_INFO, ACM, "ip_init: using file: /etc/spread.access_ip\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_ip", "r")) )
+            Alarmp( SPLOG_INFO, ACM, "ip_init: using file: " SPREAD_ETCDIR "/spread.access_ip\n");
     if (fp == NULL)
     {
         Alarmp( SPLOG_ERROR, ACM, "ip_init: IP access control file not found.\nIf you are using IP based access controls, please make sure the file exists.\n");
