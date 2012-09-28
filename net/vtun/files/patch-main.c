--- main.c.orig	2012-07-07 22:32:57.000000000 -0700
+++ main.c	2012-09-26 13:37:53.331700962 -0700
@@ -50,12 +50,14 @@
 extern int optind,opterr,optopt;
 extern char *optarg;
 
+static char* pidfile = VTUN_PID_FILE;
+
 /* for the NATHack bit.  Is our UDP session connected? */
 int is_rmt_fd_connected=1; 
 
 int main(int argc, char *argv[], char *env[])
 {
-  int svr, daemon, sock, dofork, fd, opt;
+     int svr, daemon, sock, dofork, fd, opt, has_pid = 0;
      struct vtun_host *host = NULL;
      struct sigaction sa;
      char *hst;
@@ -92,7 +94,7 @@
      /* Start logging to syslog and stderr */
      openlog("vtund", LOG_PID | LOG_NDELAY | LOG_PERROR, LOG_DAEMON);
 
-     while( (opt=getopt(argc,argv,"misf:P:L:t:npq")) != EOF ){
+     while( (opt=getopt(argc,argv,"misf:P:L:t:npz:")) != EOF ){
 	switch(opt){
 	    case 'm':
 	        if (mlockall(MCL_CURRENT | MCL_FUTURE) < 0) {
@@ -126,6 +128,10 @@
 	    case 'q':
 		vtun.quiet = 1;
 		break;
+	    case 'z':
+		pidfile = strdup(optarg);
+		has_pid = 1;
+		break;
 	    default:
 		usage();
 	        exit(1);
@@ -200,12 +206,19 @@
 
         init_title(argc,argv,env,"vtund[s]: ");
 
+	if ( has_pid )
+	   write_pid();
+
 	if( vtun.svr_type == VTUN_STAND_ALONE )	
 	   write_pid();
 	
 	server(sock);
      } else {	
         init_title(argc,argv,env,"vtund[c]: ");
+
+	if ( has_pid )
+	   write_pid();
+
         client(host);
      }
 
@@ -222,7 +235,7 @@
 {
      FILE *f;
 
-     if( !(f=fopen(VTUN_PID_FILE,"w")) ){
+     if( !(f=fopen(pidfile,"w")) ){
         vtun_syslog(LOG_ERR,"Can't write PID file");
         return;
      }
@@ -244,9 +257,9 @@
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
