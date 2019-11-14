Part of extended mode being an argument and not a compile time decision.
Some bits about using vfork, or not, and pidfile as an argument.

--- main.c.orig	2013-07-07 20:31:22 UTC
+++ main.c
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
@@ -57,6 +57,9 @@ static void usage(void);
 extern int optind,opterr,optopt;
 extern char *optarg;
 
+static char* pidfile = VTUN_PID_FILE;
+int extended_mode = 0;
+
 /* for the NATHack bit.  Is our UDP session connected? */
 int is_rmt_fd_connected=1; 
 
@@ -141,6 +144,14 @@ int main(int argc, char *argv[], char *env[])
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
@@ -233,6 +244,9 @@ int main(int argc, char *argv[], char *env[])
 	
 	server(sock);
      } else {	
+#ifdef HAVE_WORKING_FORK
+	write_pid();
+#endif
         init_title(argc,argv,env,"vtund[c]: ");
         client(host);
      }
@@ -250,7 +264,7 @@ static void write_pid(void)
 {
      FILE *f;
 
-     if( !(f=fopen(VTUN_PID_FILE,"w")) ){
+     if( !(f=fopen(pidfile,"w")) ){
         vtun_syslog(LOG_ERR,"Can't write PID file");
         return;
      }
@@ -273,12 +287,17 @@ static void usage(void)
      printf("Usage: \n");
      printf("  Server:\n");
 #ifdef HAVE_WORKING_FORK
-     printf("\tvtund <-s|-i> [-f file] [-P port] [-L local address]\n");
+     printf("\tvtund <-s|-i> [-f file] [-P port] [-L local address] [-e] [-z pid_file ]\n");
 #else
-     printf("\tvtund <-i> [-f file] [-P port] [-L local address]\n");
+     printf("\tvtund <-i> [-f file] [-P port] [-L local address] [-e]\n");
 #endif
      printf("  Client:\n");
      /* I don't think these work. I'm disabling the suggestion - bish 20050601*/
+#ifdef HAVE_WORKING_FORK
      printf("\tvtund [-f file] " /* [-P port] [-L local address] */
-	    "[-q] [-p] [-m] [-t timeout] <host profile> <server address>\n");
+	    "[-q] [-p] [-m] [-t timeout] [-e] <host profile> <server address>\n");
+#else
+     printf("\tvtund [-f file] " /* [-P port] [-L local address] */
+	    "[-q] [-p] [-m] [-t timeout] [-e] <host profile> <server address>\n");
+#endif
 }
