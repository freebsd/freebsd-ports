--- sources/log.c.orig	Wed May  5 12:12:12 2004
+++ sources/log.c	Wed May  5 12:04:57 2004
@@ -20,6 +20,7 @@
 
 int logFileOpen()
 {
+#ifdef LOG
     char timeStr[256];
     struct tm *timeStruct;
     time_t timeTemp;
@@ -37,15 +38,18 @@
 #ifdef PRINTF_DEBUG
     printf("Opened Log File.\n");
 #endif    
+#endif    
     return 0;
 }
 
 int logFileClose()
 {
+#ifdef LOG
     fclose(lf);
 #ifdef PRINTF_DEBUG
     printf("Closed Log File.\n");
 #endif    
+#endif    
     return 0;
 }
 
@@ -57,6 +61,7 @@
 struct request req;
 int code;
 {
+#ifdef LOG
     char timeStr[256];
     struct tm *timeStruct;
     time_t timeTemp;
@@ -104,6 +109,7 @@
         printf ("Unknown event to log! Programming error!\n");
     }
     fflush(lf);
+#endif
     return 0;
 }
 
