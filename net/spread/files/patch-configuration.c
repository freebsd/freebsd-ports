--- configuration.c	Mon Sep 27 00:15:48 2004
+++ configuration.c	Tue Oct  4 14:40:51 2005
@@ -130,9 +130,6 @@
 
 	if (NULL != (yyin = fopen(file_name,"r")) )
                 Alarm( PRINT, "Conf_init: using file: %s\n", file_name);
-	if (yyin == NULL) 
-		if (NULL != (yyin = fopen("./spread.conf", "r")) )
-                        Alarm( PRINT, "Conf_init: using file: ./spread.conf\n");
 	if (yyin == NULL)
 		if (NULL != (yyin = fopen(configfile_location, "r")) )
                         Alarm( PRINT, "Conf_init: using file: %s\n", configfile_location);
