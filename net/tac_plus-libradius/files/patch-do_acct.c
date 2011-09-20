--- ./do_acct.c.orig	2000-12-18 17:58:02.000000000 +0100
+++ ./do_acct.c	2011-08-29 00:31:55.000000000 +0200
@@ -21,6 +21,13 @@
 
 static int acctfd = 0;
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 900007
+# define utmp utmpx
+# define ut_time ut_tv.tv_sec
+# define ut_name ut_user
+#endif
+
+
 /* Make a acct entry into the accounting file for accounting. 
    Return 1 on error  */
 
@@ -159,7 +166,7 @@
 #endif
     entry.ut_time = utime;
 
-    wtmpfd = open(wtmpfile, O_CREAT | O_WRONLY | O_APPEND | O_SYNC, 0644);	
+    wtmpfd = open(wtmpfile, O_CREAT | O_WRONLY | O_APPEND , 0644);	
     if (wtmpfd < 0) {
 	report(LOG_ERR, "Can't open wtmp file %s -- %s",
 	       wtmpfile, sys_errlist[errno]);
