--- main.c.orig	Tue Nov 13 13:44:26 2001
+++ main.c	Tue Dec  4 17:00:15 2001
@@ -400,7 +400,7 @@
   }  
 
   snprintf(accessLogPath, sizeof(accessLogPath), "%s/%s",
-	   dbPath, DETAIL_ACCESS_LOG_FILE_PATH);
+	   accessLogPath, DETAIL_ACCESS_LOG_FILE_PATH);
 
   initLogger(); /* Do not call this function before dbPath
 		   is initialized */
