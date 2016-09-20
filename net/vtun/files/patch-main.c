--- main.c.orig	2013-07-07 13:31:22.000000000 -0700
+++ main.c	2016-09-19 18:44:42.369746000 -0700
@@ -41,7 +41,7 @@
 
 #define OPTSTRING "mif:P:L:t:npq"
 #ifdef HAVE_WORKING_FORK
-#  define SERVOPT_STRING "s"
+#  define SERVOPT_STRING "sz:"
 #else
 #  define SERVOPT_STRING ""
 #endif
@@ -57,6 +57,8 @@
 extern int optind,opterr,optopt;
 extern char *optarg;
 
+static char* pidfile = VTUN_PID_FILE;
+
 /* for the NATHack bit.  Is our UDP session connected? */
 int is_rmt_fd_connected=1; 
 
@@ -141,6 +143,11 @@
 	    case 'q':
 		vtun.quiet = 1;
 		break;
+#ifdef HAVE_WORKING_FORK
+	    case 'z':
+		pidfile = strdup(optarg);
+		break;
+#endif
 	    default:
 		usage();
 	        exit(1);
@@ -250,7 +257,7 @@
 {
      FILE *f;
 
-     if( !(f=fopen(VTUN_PID_FILE,"w")) ){
+     if( !(f=fopen(pidfile,"w")) ){
         vtun_syslog(LOG_ERR,"Can't write PID file");
         return;
      }
