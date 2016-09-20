--- main.c.orig	2013-07-07 13:31:22.000000000 -0700
+++ main.c	2016-09-19 20:05:37.120740000 -0700
@@ -39,9 +39,9 @@
 #include "lib.h"
 #include "compat.h"
 
-#define OPTSTRING "mif:P:L:t:npq"
+#define OPTSTRING "mif:P:L:t:npqe"
 #ifdef HAVE_WORKING_FORK
-#  define SERVOPT_STRING "s"
+#  define SERVOPT_STRING "sz:"
 #else
 #  define SERVOPT_STRING ""
 #endif
@@ -57,6 +57,9 @@
 extern int optind,opterr,optopt;
 extern char *optarg;
 
+static char* pidfile = VTUN_PID_FILE;
+int extended_mode = 0;
+
 /* for the NATHack bit.  Is our UDP session connected? */
 int is_rmt_fd_connected=1; 
 
@@ -141,6 +144,14 @@
 	    case 'q':
 		vtun.quiet = 1;
 		break;
+#ifdef HAVE_WORKING_FORK
+	    case 'z':
+		pidfile = strdup(optarg);
+		break;
+#endif
+	    case 'e':
+		extended_mode = 1;
+		break;
 	    default:
 		usage();
 	        exit(1);
@@ -250,7 +261,7 @@
 {
      FILE *f;
 
-     if( !(f=fopen(VTUN_PID_FILE,"w")) ){
+     if( !(f=fopen(pidfile,"w")) ){
         vtun_syslog(LOG_ERR,"Can't write PID file");
         return;
      }
