--- erpcd/session_dbunx.c.orig	Wed Oct 15 13:50:46 1997
+++ erpcd/session_dbunx.c	Thu Sep 18 20:10:32 2003
@@ -117,7 +117,11 @@
 key_t sem_key = 0;          /* semaphore key */
 int Asemid;		/* Access semaphore id */
 
+#if defined(__FreeBSD__)
+int ctlinit;
+#else
 union semun ctlinit;	/* arg struct for semctl */
+#endif
 						/* sembuf elements: index, op, flag */
 struct sembuf sopwait = {0,-1, SEM_UNDO};	/* wait for semaphore */
 struct sembuf soppost = {0, 1, SEM_UNDO};	/* set value to available */
@@ -290,7 +294,11 @@
 	return errno;
       }
     }
+#if defined(__FreeBSD__)
+    ctlinit = 1;
+#else
     ctlinit.val = 1;
+#endif
     if (semctl(Asemid, 0, SETVAL, ctlinit) == -1) {
 #ifdef USE_SYSLOG
       syslog(LOG_CRIT, "%s: Set semaphore, semctl error %d. No database access.", appname, errno);
