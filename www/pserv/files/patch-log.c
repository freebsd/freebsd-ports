--- sources/log.c.orig	Mon May 16 23:03:16 2005
+++ sources/log.c	Sat May 28 10:41:25 2005
@@ -23,6 +23,7 @@
  */
 int logFileOpen()
 {
+#ifdef LOG
     char timeStr[256];
     struct tm *timeStruct;
     time_t timeTemp;
@@ -38,6 +39,7 @@
     fflush(lf); /* otherwise we have mysterious problems with fork() !! */ 
 
     DBGPRINTF(("Opened Log File.\n"));
+#endif
     return 0;
 }
 
@@ -45,8 +47,10 @@
  */
 int logFileClose()
 {
+#ifdef LOG
     fclose(lf);
     DBGPRINTF(("Closed Log File.\n"));
+#endif
     return 0;
 }
 
@@ -61,6 +65,7 @@
 struct request req;
 int code;
 {
+#ifdef LOG
     char timeStr[256];
     struct tm *timeStruct;
     time_t timeTemp;
@@ -108,6 +113,7 @@
         printf ("Unknown event to log! Programming error!\n");
     }
     fflush(lf);
+#endif
     return 0;
 }
 
