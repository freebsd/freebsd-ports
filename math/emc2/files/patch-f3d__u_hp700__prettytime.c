--- f3d/u_hp700/prettytime.c.orig	1999-11-09 14:58:18 UTC
+++ f3d/u_hp700/prettytime.c
@@ -6,7 +6,7 @@ char *timeret;
 {
     time_t timevar;
     struct tm *pttm;
-    char buffer[12];
+    char buffer[13];
 
     timevar=time(&timevar);
     pttm = localtime(&timevar);
@@ -14,6 +14,6 @@ char *timeret;
     sprintf(buffer,"%02d%02d%02d000000",pttm->tm_hour,
                                   pttm->tm_min,
                                   pttm->tm_sec);
-    bcopy (buffer, timeret, 12);
+    bcopy (buffer, timeret, 13);
 }
       
