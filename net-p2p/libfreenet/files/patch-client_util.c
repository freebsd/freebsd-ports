--- client_util.c.orig	Wed Mar 28 03:27:38 2001
+++ client_util.c	Fri Mar 15 07:54:32 2002
@@ -37,7 +37,7 @@
 #endif
 
 
-long blstr2time(char *baseline);
+time_t blstr2time(char *baseline);
 int timediff();
 
 
@@ -60,13 +60,14 @@
 
 int timediff ()
 {
+    struct tm *tmp;
     long t = time(NULL);
 
     /* We are calling localtime here for its side-effect of setting
        the timezone global appropriately.  I have no proof that this
        even happens on cygwin.  Please, just let me die. */
-    localtime(&t);
-    return (FN_TIMEZONE / 3600);
+    tmp = localtime(&t);
+    return (tmp->tm_gmtoff / 3600);
 }
 
 
