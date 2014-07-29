--- webclient.c.orig	1998-07-25 09:50:17.000000000 +0200
+++ webclient.c	2011-12-20 19:15:12.739176097 +0100
@@ -79,7 +79,7 @@
 char	proxyserver[MAXHOSTNAMELEN];
 char	debug_filename[MAXPATHLEN];
 
-THREAD FILE	*debugfile = stderr;
+THREAD FILE	*debugfile;
 THREAD FILE	*logfile;
 THREAD stats_t	timestat;
 THREAD rqst_timer_t	timerarray[MAXNUMOFFILES];
@@ -691,7 +691,7 @@
 	}
 }
 
-void
+int
 main(int argc, char *argv[])
 {
 	long	fcount = 0;
@@ -928,7 +928,7 @@
 	CloseHandle(hSemaphore);
 #endif /* WIN32 */
 
-    return;
+	return(0);
 }
 
 void 
