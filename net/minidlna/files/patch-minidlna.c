--- minidlna.c	2012-02-14 13:26:53.000000000 -0500
+++ minidlna.c	2012-04-11 11:18:28.000000000 -0400
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
 
@@ -86,5 +91,7 @@
 #include "upnpevents.h"
 #include "scanner.h"
+#ifdef __linux__
 #include "inotify.h"
+#endif
 #include "log.h"
 #ifdef TIVO_SUPPORT
@@ -342,5 +349,5 @@
 	struct sigaction sa;
 	const char * presurl = NULL;
-	const char * optionsfile = "/etc/minidlna.conf";
+	const char * optionsfile = PREFIX "/etc/minidlna.conf";
 	char mac_str[13];
 	char * string, * word;
@@ -352,4 +359,5 @@
 	char *log_level = NULL;
 
+	uid_t	uid = (uid_t)-1;
 	/* first check if "-f" option is used */
 	for(i=2; i<argc; i++)
@@ -740,4 +748,21 @@
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
 			DPRINTF(E_ERROR, L_GENERAL, "Unknown option: %s\n", argv[i]);
@@ -767,4 +792,5 @@
 			"\t\t[-s serial] [-m model_number] \n"
 			"\t\t[-t notify_interval] [-P pid_filename]\n"
+			"\t\t[-u uid_to_run_as]\n"
 			"\t\t[-w url] [-R] [-V] [-h]\n"
 		        "\nNotes:\n\tNotify interval is in seconds. Default is 895 seconds.\n"
@@ -839,4 +865,7 @@
 	writepidfile(pidfilename, pid);
 
+	if (uid != (uid_t)-1 && setuid(uid) == -1)
+		err(EX_NOPERM, "setuid(%ld)", (long)uid);
+
 	return 0;
 }
@@ -965,4 +995,5 @@
 	}
 	signal(SIGCHLD, SIG_IGN);
+#if defined(__linux__)
 	if( sqlite3_threadsafe() && sqlite3_libversion_number() >= 3005001 &&
 	    GETFLAG(INOTIFY_MASK) && pthread_create(&inotify_thread, NULL, start_inotify, NULL) )
@@ -970,6 +1001,7 @@
 		DPRINTF(E_FATAL, L_GENERAL, "ERROR: pthread_create() failed for start_inotify.\n");
 	}
+#endif
 
-	sudp = OpenAndConfSSDPReceiveSocket(n_lan_addr, lan_addr);
+	sudp = OpenAndConfSSDPReceiveSocket();
 	if(sudp < 0)
 	{
