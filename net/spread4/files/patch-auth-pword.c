--- auth-pword.c	Sun Sep 22 12:56:52 2002
+++ auth-pword.c	Wed Nov  6 02:40:23 2002
@@ -122,8 +122,8 @@
         if (NULL != (fp = fopen("./spread.access_pword", "r")) )
             Alarm( PRINT, "pword_init: using file: ./spread.access_pword\n");
     if (fp == NULL)
-        if (NULL != (fp = fopen("/etc/spread.access_pword", "r")) )
-            Alarm( PRINT, "pword_init: using file: /etc/spread.access_pword\n");
+        if (NULL != (fp = fopen(SPREAD_ETCDIR "/spread.access_pword", "r")) )
+            Alarm( PRINT, "pword_init: using file: " SPREAD_ETCDIR "/spread.access_pword\n");
     if (fp == NULL)
         Alarm( EXIT, "pword_init: error opening config file %s in any of the standard locations. Please make sure the file exists\n", file_name);
 
