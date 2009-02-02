--- ./src/facts.c.orig	2006-03-07 15:44:32.000000000 +0100
+++ ./src/facts.c	2009-01-29 17:46:58.478243916 +0100
@@ -2563,7 +2563,7 @@
 #else
 		/* assume sh */
 		snprintf(cmd, sizeof cmd, "%s -T%s -o %s/tmp.lanmap %s && mv %s/tmp.lanmap %slanmap.%s && rm %s",
-			Run_Program, Image_Type, xstr(LANMAP_DATADIR), DOT_FILE, xstr(LANMAP_DATADIR), Output_Dir, Image_Type, DOT_FILE);
+			Run_Program, Image_Type, xstr(LANMAP_DATATMP), DOT_FILE, xstr(LANMAP_DATATMP), Output_Dir, Image_Type, DOT_FILE);
 #endif
 		printf("cmd:%s\n",cmd);
 		DEBUGF(__FILE__, __LINE__, "cmd: %s", cmd);
