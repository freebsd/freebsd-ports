--- client_util.c.orig	Wed Mar 28 19:27:38 2001
+++ client_util.c	Sat Mar 31 15:07:59 2001
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
 
 
