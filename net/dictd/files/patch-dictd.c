--- dictd.c.orig	Mon Jun 10 02:39:20 2002
+++ dictd.c	Mon Jun 10 02:40:01 2002
@@ -113,7 +113,7 @@
 
 static void reaper( int dummy )
 {
-#if defined(__osf__) || (defined(__sparc) && defined(__SVR4))
+#if defined(__FreeBSD__) || defined(__osf__) || (defined(__sparc) && defined(__SVR4))
    int        status;
 #else
    union wait status;
