
$FreeBSD$

--- coreapi/misc.c.orig	Sat Aug  9 00:10:47 2003
+++ coreapi/misc.c	Sat Aug 23 00:08:50 2003
@@ -93,7 +93,7 @@
 	pid_t pid;
 	
 	/* try to kill all artsd*/
-	command=g_strdup_printf("ps -u %s |grep artsd",getenv("LOGNAME"));
+	command=g_strdup_printf("ps -c %s |grep artsd",getenv("LOGNAME"));
 	out=popen(command,"r");
 	if (out!=NULL)
 	{
@@ -123,7 +123,7 @@
 	g_free(command);
 	
 	/* do the same with esd*/
-	command=g_strdup_printf("ps -u %s |grep esd",getenv("LOGNAME"));
+	command=g_strdup_printf("ps -c %s |grep esd",getenv("LOGNAME"));
 	out=popen(command,"r");
 	if (out!=NULL)
 	{
