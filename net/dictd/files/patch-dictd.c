--- dictd.c~	Mon Jan 29 01:51:25 2001
+++ dictd.c	Mon Jan 29 01:59:29 2001
@@ -97,7 +97,7 @@
 
 static void reaper( int dummy )
 {
-#if defined(__osf__) || (defined(__sparc__) && defined(__svr4__))
+#if defined(__FreeBSD__) || defined(__osf__) || (defined(__sparc__) && defined(__svr4__) )
    int        status;
 #else
    union wait status;
