--- webmaster.c.orig	1998-07-25 09:50:18.000000000 +0200
+++ webmaster.c	2011-12-20 19:14:07.911175579 +0100
@@ -88,7 +88,7 @@
 SOCKET	    socknum[MAXCLIENTS];
 SOCKET	    sockIO[MAXTOTALPROCS];
 SOCKET	    sockErr[MAXTOTALPROCS];
-THREAD FILE *debugfile = stderr;	    
+THREAD FILE *debugfile;   
 
 struct hostent  *master_phe;   /* IP addresses for webmaster */
 
@@ -1343,7 +1343,7 @@
 }
 #endif /* WIN32 */
 
-void
+int
 main(const int argc, char *argv[])
 {
 
@@ -1385,6 +1385,7 @@
 
     /* Initalization of variables. */
     /* debugfile = stdout; */
+    debugfile = stderr;
     memset(buffer, 0, NCCARGS);
     memset(webserver, 0, MAXHOSTNAMELEN);
     memset(configfile, 0, MAXPATHLEN);
