--- authenticate.c.orig	Sun Jan 25 13:49:01 2004
+++ authenticate.c	Sun Jan 25 13:49:33 2004
@@ -195,7 +195,7 @@
       syslog(LOG_ERR,"%s: %s: %s","failed to read auth file",authfile,strerror(errno));
       return 0;
     }
-    while ((0!=ferror(fptr)) && (0!=feof(fptr))) {
+    while ((!ferror(fptr)) && (!feof(fptr))) {
       linebuf[0] = '\0';
       if (fgets(linebuf, sizeof(linebuf), fptr) == NULL) {
         fclose(fptr);
