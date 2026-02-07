--- f3d/u_hp700/prettydate.c.orig	1999-11-09 14:58:17 UTC
+++ f3d/u_hp700/prettydate.c
@@ -6,7 +6,7 @@ char *date;
 {
     time_t timevar;
     struct tm *pttm;
-    char buffer[6];
+    char buffer[7];
 
     timevar=time(&timevar);
     pttm = localtime(&timevar);
@@ -14,6 +14,6 @@ char *date;
     sprintf(buffer,"%02d%02d%02d",pttm->tm_year % 100,
                                   pttm->tm_mon+1,
                                   pttm->tm_mday);
-    bcopy (buffer, date, 6);
+    bcopy (buffer, date, 7);
 }
       
