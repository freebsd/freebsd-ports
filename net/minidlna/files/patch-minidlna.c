--- minidlna.c	2011-07-18 18:18:11.000000000 -0400
+++ minidlna.c	2011-08-24 01:25:26.000000000 -0400
@@ -53,4 +53,5 @@
 #include <ctype.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -66,4 +67,8 @@
 #include <pwd.h>
 
+#include <err.h>
+#include <stdint.h>
+#include <sysexits.h>
+
 #include "config.h"
 
@@ -345,5 +350,5 @@
 	/*const char * logfilename = 0;*/
 	const char * presurl = 0;
-	const char * optionsfile = "/etc/minidlna.conf";
+	const char * optionsfile = PREFIX "/etc/minidlna.conf";
 	char mac_str[13];
 	char * string, * word;
@@ -353,4 +358,5 @@
 	char ip_addr[INET_ADDRSTRLEN + 3] = {'\0'};
 
+	uid_t	uid = (uid_t)-1;
 	/* first check if "-f" option is used */
 	for(i=2; i<argc; i++)
@@ -741,4 +747,21 @@
 			exit(0);
 			break;
+		case 'u':
+			if(i+1 == argc)
+				err(EX_USAGE, "Option -%c takes one argument.", argv[i][1]);
+			else {
+				char *endp;
+				i++;
+				uid = strtol(argv[i], &endp, 0);
+				if (*endp) {
+					/* Symbolic username given, not UID. */
+					struct passwd *entry = getpwnam(argv[i]);
+
+					if (entry == NULL)
+						err(EX_NOUSER, "%s", argv[i]);
+					uid = entry->pw_uid;
+				}
+			}
+			break;
 		default:
 			fprintf(stderr, "Unknown option: %s\n", argv[i]);
@@ -768,4 +791,5 @@
 			"\t\t[-s serial] [-m model_number] \n"
 			"\t\t[-t notify_interval] [-P pid_filename]\n"
+			"\t\t[-u uid_to_run_as]\n"
 			"\t\t[-w url] [-R] [-V] [-h]\n"
 		        "\nNotes:\n\tNotify interval is in seconds. Default is 895 seconds.\n"
@@ -831,5 +855,5 @@
 
 	/* set signal handler */
-	signal(SIGCLD, SIG_IGN);
+	signal(SIGCHLD, SIG_IGN);
 	memset(&sa, 0, sizeof(struct sigaction));
 	sa.sa_handler = sigterm;
@@ -849,4 +878,7 @@
 	writepidfile(pidfilename, pid);
 
+	if (uid != (uid_t)-1 && setuid(uid) == -1)
+		err(EX_NOPERM, "setuid(%ld)", (long)uid);
+
 	return 0;
 }
@@ -966,4 +998,5 @@
 #endif
 	}
+#if defined(__linux__)
 	if( sqlite3_threadsafe() && sqlite3_libversion_number() >= 3005001 &&
 	    GETFLAG(INOTIFY_MASK) && pthread_create(&inotify_thread, NULL, start_inotify, NULL) )
@@ -971,4 +1004,5 @@
 		DPRINTF(E_FATAL, L_GENERAL, "ERROR: pthread_create() failed for start_inotify.\n");
 	}
+#endif
 
 	sudp = OpenAndConfSSDPReceiveSocket(n_lan_addr, lan_addr);
