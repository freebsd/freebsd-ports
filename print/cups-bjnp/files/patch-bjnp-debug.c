--- bjnp-debug.c.orig	2018-02-21 11:40:53 UTC
+++ bjnp-debug.c
@@ -20,7 +20,7 @@
 
 #include <stdio.h>
 #include <stdarg.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <errno.h>
 #include "bjnp.h"
 
@@ -58,7 +58,7 @@ static logtable_entry_t logtable[] = {
 static bjnp_loglevel_t debug_level = LOG_ERROR;
 static FILE *debug_file = NULL;
 static time_t start_sec = 0;
-static int start_msec;
+static suseconds_t start_usec;
 
 /*
  * local functions
@@ -192,9 +192,9 @@ bjnp_debug(bjnp_loglevel_t level, const char *fmt, ...
 {
     va_list ap;
     char printbuf[1024];
-    struct timeb timebuf;
+    struct timeval timebuf;
     int sec;
-    int msec;
+    suseconds_t usec;
 
     if (level <= debug_level) {
         /* print received data into a string */
@@ -211,16 +211,16 @@ bjnp_debug(bjnp_loglevel_t level, const char *fmt, ...
         /* all log messages may go to the own logfile */
 
         if (debug_file != NULL) {
-            ftime(&timebuf);
+	    gettimeofday (&timebuf, NULL);
 
-            if ((msec = timebuf.millitm - start_msec) < 0) {
-                msec += 1000;
-                timebuf.time -= 1;
+            if ((usec = timebuf.tv_usec - start_usec) < 0) {
+                usec += 1000000;
+                timebuf.tv_sec -= 1;
             }
 
-            sec = timebuf.time - start_sec;
+            sec = timebuf.tv_sec - start_sec;
 
-            fprintf(debug_file, "%8s: %03d.%03d %s", level2str(level), sec, msec,
+            fprintf(debug_file, "%8s: %03d.%06ld %s", level2str(level), sec, usec,
                     printbuf);
             fflush(debug_file);
         }
@@ -234,12 +234,12 @@ bjnp_set_debug_level(const char *level, const char *fi
      * set debug level to level (string)
      */
 
-    struct timeb timebuf;
+    struct timeval timebuf;
     char loglevel[16];
 
-    ftime(&timebuf);
-    start_sec = timebuf.time;
-    start_msec = timebuf.millitm;
+    gettimeofday (&timebuf, NULL);
+    start_sec = timebuf.tv_sec;
+    start_usec = timebuf.tv_usec;
 
     /*
      * Set log level
