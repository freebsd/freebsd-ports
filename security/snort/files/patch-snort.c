--- snort.c.orig	Fri Jun 28 10:22:59 2002
+++ snort.c	Sat Jul 13 11:13:16 2002
@@ -1694,7 +1694,7 @@
     difftime.tv_sec = endtime.tv_sec - starttime.tv_sec;
     difftime.tv_usec = endtime.tv_usec - starttime.tv_usec;
 
-    printf("Run time for packet processing was %u.%u seconds\n", 
+    printf("Run time for packet processing was %lu.%lu seconds\n", 
             difftime.tv_sec, difftime.tv_usec);
 
     CleanExit(SIGQUIT);
