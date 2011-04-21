--- main.c.orig	2008-01-08 07:35:53.000000000 +0900
+++ main.c	2011-04-21 23:54:45.376770964 +0900
@@ -50,9 +50,11 @@
 extern int optind,opterr,optopt;
 extern char *optarg;
 
+static char* pidfile = VTUN_PID_FILE;
+
 int main(int argc, char *argv[], char *env[])
 {
-     int svr, daemon, sock, dofork, fd, opt;
+     int svr, daemon, sock, dofork, fd, opt, has_pid = 0;
      struct vtun_host *host = NULL;
      struct sigaction sa;
      char *hst;
@@ -89,7 +91,7 @@
      /* Start logging to syslog and stderr */
      openlog("vtund", LOG_PID | LOG_NDELAY | LOG_PERROR, LOG_DAEMON);
 
-     while( (opt=getopt(argc,argv,"misf:P:L:t:np")) != EOF ){
+     while( (opt=getopt(argc,argv,"misf:P:L:t:npz:")) != EOF ){
 	switch(opt){
 	    case 'm':
 	        if (mlockall(MCL_CURRENT | MCL_FUTURE) < 0) {
@@ -120,6 +122,10 @@
 	    case 't':
 	        vtun.timeout = atoi(optarg);	
 	        break;
+	    case 'z':
+	        pidfile = strdup(optarg);
+		has_pid = 1;
+	        break;
 	    default:
 		usage();
 	        exit(1);
@@ -198,6 +204,10 @@
 	server(sock);
      } else {	
         init_title(argc,argv,env,"vtund[c]: ");
+
+	if ( has_pid )
+	   write_pid();
+
         client(host);
      }
 
@@ -214,7 +224,7 @@
 {
      FILE *f;
 
-     if( !(f=fopen(VTUN_PID_FILE,"w")) ){
+     if( !(f=fopen(pidfile,"w")) ){
         vtun_syslog(LOG_ERR,"Can't write PID file");
         return;
      }
@@ -236,9 +246,9 @@
      printf("VTun ver %s\n", VTUN_VER);
      printf("Usage: \n");
      printf("  Server:\n");
-     printf("\tvtund <-s> [-f file] [-P port] [-L local address]\n");
+     printf("\tvtund <-s> [-f file] [-P port] [-L local address] [-z pidfile]\n");
      printf("  Client:\n");
      /* I don't think these work. I'm disabling the suggestion - bish 20050601*/
      printf("\tvtund [-f file] " /* [-P port] [-L local address] */
-	    "[-p] [-m] [-t timeout] <host profile> <server address>\n");
+	    "[-p] [-m] [-t timeout] [-z pidfile] <host profile> <server address>\n");
 }
