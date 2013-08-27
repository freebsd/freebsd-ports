--- bjnp-debug.c.orig	2013-01-21 10:43:27.000000000 -0800
+++ bjnp-debug.c	2013-08-14 02:29:30.000000000 -0700
@@ -19,7 +19,7 @@
 
 #include <stdio.h>
 #include <stdarg.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <errno.h>
 #include "bjnp.h"
 
@@ -59,7 +59,7 @@
 static int to_cups = 0;
 static FILE *debug_file = NULL;
 static time_t start_sec = 0;
-static int start_msec;
+static suseconds_t start_usec;
 
 /* 
  * local functions
@@ -186,9 +186,9 @@
 {
   va_list ap;
   char printbuf[256];
-  struct timeb timebuf;
+  struct timeval timebuf;
   int sec;
-  int msec;
+  suseconds_t usec;
 
   /* print received data into a string */
   va_start (ap, fmt);
@@ -204,15 +204,15 @@
 
   if ((level <= debug_level) && debug_file)
     {
-      ftime (&timebuf);
-      if ((msec = timebuf.millitm - start_msec) < 0)
+      gettimeofday (&timebuf, NULL);
+      if ((usec = timebuf.tv_usec - start_usec) < 0)
 	{
-	  msec += 1000;
-	  timebuf.time -= 1;
+	  usec += 1000000;
+	  timebuf.tv_sec -= 1;
 	}
-      sec = timebuf.time - start_sec;
+      sec = timebuf.tv_sec - start_sec;
 
-      fprintf (debug_file, "%8s: %03d.%03d %s", level2str (level), sec, msec,
+      fprintf (debug_file, "%8s: %03d.%06ld %s", level2str (level), sec, usec,
 	       printbuf);
     }
 }
@@ -224,13 +224,13 @@
    * set debug level to level (string)
    */
 
-  struct timeb timebuf;
+  struct timeval timebuf;
   char loglevel[16];
   char *separator;
   
-  ftime (&timebuf);
-  start_sec = timebuf.time;
-  start_msec = timebuf.millitm;
+  gettimeofday (&timebuf, NULL);
+  start_sec = timebuf.tv_sec;
+  start_usec = timebuf.tv_usec;
 
   /*
    * Split string into loglevel and optional cupslog string
