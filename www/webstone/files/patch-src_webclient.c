--- src/webclient.c.orig	1998-07-25 07:50:17 UTC
+++ src/webclient.c
@@ -79,7 +79,7 @@ char	webserver[MAXHOSTNAMELEN];
 char	proxyserver[MAXHOSTNAMELEN];
 char	debug_filename[MAXPATHLEN];
 
-THREAD FILE	*debugfile = stderr;
+THREAD FILE	*debugfile;
 THREAD FILE	*logfile;
 THREAD stats_t	timestat;
 THREAD rqst_timer_t	timerarray[MAXNUMOFFILES];
@@ -691,7 +691,7 @@ ParseCmdLine(int argc, char **argv )
 	}
 }
 
-void
+int
 main(int argc, char *argv[])
 {
 	long	fcount = 0;
@@ -928,7 +928,7 @@ main(int argc, char *argv[])
 	CloseHandle(hSemaphore);
 #endif /* WIN32 */
 
-    return;
+	return(0);
 }
 
 void 
