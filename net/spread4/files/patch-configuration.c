--- configuration.c	Sun Sep 22 12:56:52 2002
+++ configuration.c	Tue Aug  5 21:24:19 2003
@@ -128,9 +128,6 @@
 
 	if (NULL != (yyin = fopen(file_name,"r")) )
                 Alarm( PRINT, "Conf_init: using file: %s\n", file_name);
-	if (yyin == NULL) 
-		if (NULL != (yyin = fopen("./spread.conf", "r")) )
-                        Alarm( PRINT, "Conf_init: using file: ./spread.conf\n");
 	if (yyin == NULL)
 		if (NULL != (yyin = fopen(configfile_location, "r")) )
                         Alarm( PRINT, "Conf_init: using file: %s\n", configfile_location);
