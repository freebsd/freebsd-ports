--- auth-pword.c	Sun Sep 22 12:56:52 2002
+++ auth-pword.c	Tue Aug  5 21:28:50 2003
@@ -118,12 +118,9 @@
     /* load spread.access_ip file */
     if (NULL != (fp = fopen(file_name,"r")) )
         Alarm( PRINT, "pword_init: using file: %s\n", file_name);
-    if (fp == NULL) 
-        if (NULL != (fp = fopen("./spread.access_pword", "r")) )
-            Alarm( PRINT, "pword_init: using file: ./spread.access_pword\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_pword", "r")) )
-            Alarm( PRINT, "pword_init: using file: /etc/spread.access_pword\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_pword", "r")) )
+            Alarm( PRINT, "pword_init: using file: " SPREAD_ETCDIR "/spread.access_pword\n");
     if (fp == NULL)
         Alarm( EXIT, "pword_init: error opening config file %s in any of the standard locations. Please make sure the file exists\n", file_name);
 
