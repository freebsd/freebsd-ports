Index: src/log.c
===================================================================
RCS file: /cvsroot/mpd/mpd/src/log.c,v
retrieving revision 1.4
retrieving revision 1.4.2.1
diff -u -r1.4 -r1.4.2.1
--- src/log.c	25 Nov 2002 23:51:41 -0000	1.4
+++ src/log.c	7 Oct 2004 22:43:31 -0000	1.4.2.1
@@ -265,17 +265,21 @@
 {
   va_list	args;
 
-  va_start(args, fmt);
   LogTimeStamp(logprintf);
+  va_start(args, fmt);
   vlogprintf(fmt, args);
+  va_end(args);
+  va_start(args, fmt);
   vlogprintf("\n", args);		/* XXX args will be ignored */
+  va_end(args);
   if (gLogOptions & LG_CONSOLE)
   {
+    va_start(args, fmt);
     vfprintf(stdout, fmt, args);
+    va_end(args);
     putc('\n', stdout);
     fflush(stdout);
   }
-  va_end(args);
 }
 
 /*
@@ -315,12 +319,16 @@
 
 /* Dump it */
 
-  va_start(ap, fmt);
-  if (console)
+  if (console) {
+    va_start(ap, fmt);
     LogDoDumpBp(printf, vprintf, FALSE, bp, fmt, ap);
-  if (log)
+    va_end(ap);
+  }
+  if (log) {
+    va_start(ap, fmt);
     LogDoDumpBp(logprintf, vlogprintf, TRUE, bp, fmt, ap);
-  va_end(ap);
+    va_end(ap);
+  }
 }
 
 /*
@@ -342,11 +350,16 @@
 
 /* Dump it */
 
-  va_start(ap, fmt);
-  if (console)
+  if (console) {
+    va_start(ap, fmt);
     LogDoDumpBuf(printf, vprintf, FALSE, buf, count, fmt, ap);
-  if (log)
+    va_end(ap);
+  }
+  if (log) {
+    va_start(ap, fmt);
     LogDoDumpBuf(logprintf, vlogprintf, TRUE, buf, count, fmt, ap);
+    va_end(ap);
+  }
 }
 
 /*
