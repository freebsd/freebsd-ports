--- src/qscan.c.orig	Fri Oct  4 20:44:37 2002
+++ src/qscan.c	Thu Apr  8 16:47:28 2004
@@ -326,8 +326,8 @@
         wait_everybody_and_die(99);
     }
     while (fgets(line, (int) sizeof line, avfp) != NULL) {
-        if (strncmp(SWEEP_VIRUS_PREFIX, line,
-                    sizeof SWEEP_VIRUS_PREFIX - (size_t) 1U) == 0) {
+        register char *virus;
+        if ((virus = strstr(line, SWEEP_VIRUS_PREFIX)) != NULL) {
             register char *crlf;
 
             if (ret < INT_MAX) {
@@ -340,8 +340,9 @@
                    (crlf = strrchr(line, '\r')) != NULL) {
                 *crlf = 0;
             }
-            *foundvirus = strdup(line + 
-                                 sizeof SWEEP_VIRUS_PREFIX - (size_t) 1U);
+            *virus = 0;
+            virus = strrchr(line, ' ');
+            *foundvirus = strdup(++virus);
         }        
     }
     if (fclose(avfp) != 0) {
@@ -479,7 +480,7 @@
         perror_log("unable to create the destdir name");
         return -1;
     }        
-    if (mkdir(ripmime_destdir, (mode_t) 0700) != 0) {
+    if (mkdir(ripmime_destdir, (mode_t) 0750) != 0) {
         if (chdir(ripmime_destdir) != 0) {
             perror_log("unable to create/access ripmime_destdir");
             return -1;
