--- debug.c.orig	Fri Sep 29 11:54:42 2006
+++ debug.c	Fri Sep 29 11:55:06 2006
@@ -378,6 +378,7 @@
     static char fmt[211] = "warning - ";
     char *msg;
     struct timeval now;
+    time_t now_sec;
     struct tm *thyme;
     
     va_start(ap, format);
@@ -394,6 +395,7 @@
     char *msg;
     char tbuf[20];
     struct timeval now;
+    time_t now_sec;
     struct tm *thyme;
     
     va_start(ap);
@@ -408,7 +410,8 @@
      */
     if (haveterminal && (debug || severity <= LOG_WARNING)) {
 	gettimeofday(&now,NULL);
-	thyme = localtime(&now.tv_sec);
+	now_sec = now.tv_sec;
+	thyme = localtime(&now_sec);
 	if (!debug)
 	    fprintf(stderr, "%s: ", progname);
 	fprintf(stderr, "%02d:%02d:%02d.%03ld %s", thyme->tm_hour,
