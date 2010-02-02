--- src/acct.c.orig	2006-02-08 18:05:53.000000000 +0100
+++ src/acct.c	2010-01-27 07:05:49.000000000 +0100
@@ -167,8 +167,13 @@
 #ifdef __svr4__
 	wt->ut_xtime = ut->time;
 #else
+#if defined(__FreeBSD__) && __FreeBSD_version > 900007
+	wt->ut_tv.tv_sec = ut->time;
+	wt->ut_tv.tv_usec = 0;
+#else
 	wt->ut_time = ut->time;
 #endif
+#endif
 #ifdef USER_PROCESS
 	/*
 	 *	And we can use the ID field to store
