
	

--- coreapi/misc.c.orig	Wed Mar 12 09:52:05 2003
+++ coreapi/misc.c	Wed Mar 12 09:52:39 2003
@@ -87,7 +87,7 @@
 	pid_t pid;
 	
 	/* try to kill all artsd*/
-	command=g_strdup_printf("ps -u %s |grep artsd",getenv("LOGNAME"));
+	command=g_strdup_printf("ps -c %s |grep artsd",getenv("LOGNAME"));
 	out=popen(command,"r");
 	if (out!=NULL)
 	{
@@ -102,7 +102,7 @@
 	}
 	g_free(command);
 	/* do the same with esd*/
-	command=g_strdup_printf("ps -u %s |grep esd",getenv("LOGNAME"));
+	command=g_strdup_printf("ps -c %s |grep esd",getenv("LOGNAME"));
 	out=popen(command,"r");
 	if (out!=NULL)
 	{
