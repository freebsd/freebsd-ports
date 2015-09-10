--- src/webmaster.c.orig	1998-07-25 07:50:18 UTC
+++ src/webmaster.c
@@ -88,7 +88,7 @@ int	    num_rexecs = 0;
 SOCKET	    socknum[MAXCLIENTS];
 SOCKET	    sockIO[MAXTOTALPROCS];
 SOCKET	    sockErr[MAXTOTALPROCS];
-THREAD FILE *debugfile = stderr;	    
+THREAD FILE *debugfile;   
 
 struct hostent  *master_phe;   /* IP addresses for webmaster */
 
@@ -1343,7 +1343,7 @@ sock_cleanup(void) 
 }
 #endif /* WIN32 */
 
-void
+int
 main(const int argc, char *argv[])
 {
 
@@ -1385,6 +1385,7 @@ main(const int argc, char *argv[])
 
     /* Initalization of variables. */
     /* debugfile = stdout; */
+    debugfile = stderr;
     memset(buffer, 0, NCCARGS);
     memset(webserver, 0, MAXHOSTNAMELEN);
     memset(configfile, 0, MAXPATHLEN);
