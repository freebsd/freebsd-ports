--- jabberd/lib/jutil.cc.orig	Tue Jul 17 16:03:22 2007
+++ jabberd/lib/jutil.cc	Tue Jul 17 16:04:28 2007
@@ -261,7 +261,7 @@
     struct tm *new_time = NULL;
 
     gettimeofday(&tv, &tz);
-    new_time = gmtime(&(tv.tv_sec));
+    new_time = gmtime((time_t *)&(tv.tv_sec));
     snprintf(buffer, sizeof(char[25]), "%d-%02d-%02dT%02d:%02d:%02d.%03dZ", 1900+new_time->tm_year,
 	     new_time->tm_mon+1, new_time->tm_mday, new_time->tm_hour,
 	     new_time->tm_min, new_time->tm_sec, tv.tv_usec/1000);
