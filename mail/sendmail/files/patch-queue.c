Index: queue.c
===================================================================
RCS file: /cvs/sendmail/queue.c,v
retrieving revision 8.954
retrieving revision 8.954.2.2
diff -u -r8.954 -r8.954.2.2
--- sendmail/queue.c	22 Apr 2006 01:07:00 -0000	8.954
+++ sendmail/queue.c	14 Jun 2006 21:50:56 -0000	8.954.2.2
@@ -6695,8 +6695,7 @@
 	static time_t nextupdate = 0;
 
 #if SM_CONF_SHM
-	/* only the daemon updates this structure */
-	if (ShmId == SM_SHM_NO_ID || DaemonPid != CurrentPid)
+	if (ShmId == SM_SHM_NO_ID && DaemonPid != CurrentPid)
 		return;
 #endif /* SM_CONF_SHM */
 	now = curtime();
