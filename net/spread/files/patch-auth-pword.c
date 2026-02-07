--- auth-pword.c	Fri Mar  5 11:32:46 2004
+++ auth-pword.c	Thu Jul 15 21:40:16 2004
@@ -118,12 +118,9 @@
     /* load spread.access_ip file */
     if (NULL != (fp = fopen(file_name,"r")) )
         Alarmp( SPLOG_INFO, ACM, "pword_init: using file: %s\n", file_name);
-    if (fp == NULL) 
-        if (NULL != (fp = fopen("./spread.access_pword", "r")) )
-            Alarmp( SPLOG_INFO,ACM, "pword_init: using file: ./spread.access_pword\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_pword", "r")) )
-            Alarmp( SPLOG_INFO, ACM, "pword_init: using file: /etc/spread.access_pword\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_pword", "r")) )
+            Alarmp( SPLOG_INFO, ACM, "pword_init: using file: " SPREAD_ETCDIR "/spread.access_pword\n");
     if (fp == NULL)
         Alarmp( SPLOG_FATAL, ACM, "pword_init: error opening config file %s in any of the standard locations. Please make sure the file exists\n", file_name);
 
