--- util.orig	Tue Jul 12 11:43:06 2005
+++ util.c	Tue Jul 12 11:43:32 2005
@@ -187,7 +187,7 @@
 	if (debug==0 || debug==1)
 	{
 		openlog("nbSMTP", LOG_PID, LOG_MAIL);
-		syslog(priority,buffer);
+		syslog(priority,"%s",buffer);
 		closelog();
 	}
 	else /* if (debug==2) */
