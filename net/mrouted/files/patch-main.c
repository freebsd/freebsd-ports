--- main.c.orig	Sun Mar  1 01:49:00 1998
+++ main.c	Thu Sep 28 21:44:08 2006
@@ -934,6 +934,7 @@
     static char fmt[211] = "warning - ";
     char *msg;
     struct timeval now;
+    time_t now_sec;
     struct tm *thyme;
 #ifdef RINGBUFFER
     static int ringbufinit = 0;
@@ -953,6 +954,7 @@
     char *msg;
     char tbuf[20];
     struct timeval now;
+    time_t now_sec;
     struct tm *thyme;
 #ifdef RINGBUFFER
     static int ringbufinit = 0;
@@ -979,7 +981,8 @@
 	ringbufinit = 1;
     }
     gettimeofday(&now,NULL);
-    thyme = localtime(&now.tv_sec);
+    now_sec = now.tv_sec;
+    thyme = localtime(&now_sec);
     sprintf(logmsg[logmsgno++], "%02d:%02d:%02d.%03ld %s err %d",
 		    thyme->tm_hour, thyme->tm_min, thyme->tm_sec,
 		    now.tv_usec / 1000, msg, syserr);
@@ -992,7 +995,8 @@
      */
     if (haveterminal && (debug || severity <= LOG_WARNING)) {
 	gettimeofday(&now,NULL);
-	thyme = localtime(&now.tv_sec);
+	now_sec = now.tv_sec;
+	thyme = localtime(&now_sec);
 	if (!debug)
 	    fprintf(stderr, "%s: ", progname);
 	fprintf(stderr, "%02d:%02d:%02d.%03ld %s", thyme->tm_hour,
