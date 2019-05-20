--- linenoise.c.orig	2019-05-17 19:45:12 UTC
+++ linenoise.c
@@ -749,7 +749,7 @@ static int linenoiseEdit(int stdin_fd, int stdout_fd, 
 
     if (write(l.ofd,prompt,l.plen) == -1) return -1;
     while(1) {
-        char c;
+        signed char c;
         int nread;
         char seq[3];
 
