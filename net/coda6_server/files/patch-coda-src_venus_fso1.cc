--- coda-src/venus/fso1.cc.orig	Thu Oct  5 16:11:23 2006
+++ coda-src/venus/fso1.cc	Thu Oct  5 16:18:40 2006
@@ -2895,7 +2895,7 @@
     char confstr[4];
     
 	close(pfd[1]);
-    if(setpgrp() < 0) { perror("setpgrp"); exit(EXIT_FAILURE); }
+    if(setpgid(0, 0) < 0) { perror("setpgid"); exit(EXIT_FAILURE); }
     
     sprintf(confstr, "%d", conflict_type);
 
