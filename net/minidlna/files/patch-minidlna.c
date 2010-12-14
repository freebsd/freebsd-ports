--- minidlna.c	2010-12-14 00:35:56.000000000 -0500
+++ minidlna.c	2010-12-14 00:38:02.000000000 -0500
@@ -67,4 +67,8 @@
 #include <pwd.h>
 
+#include <err.h>
+#include <stdint.h>
+#include <sysexits.h>
+
 #include "config.h"
 
@@ -282,5 +286,5 @@
 	/*const char * logfilename = 0;*/
 	const char * presurl = 0;
-	const char * optionsfile = "/etc/minidlna.conf";
+	const char * optionsfile = PREFIX "/etc/minidlna.conf";
 	char mac_str[13];
 	char * string, * word;
@@ -289,4 +293,5 @@
 	char real_path[PATH_MAX];
 	char ext_ip_addr[INET_ADDRSTRLEN] = {'\0'};
+	uid_t	uid = (uid_t)-1;
 
 	/* first check if "-f" option is used */
@@ -617,4 +622,21 @@
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
@@ -644,4 +666,5 @@
 			"\t\t[-s serial] [-m model_number] \n"
 			"\t\t[-t notify_interval] [-P pid_filename]\n"
+			"\t\t[-u uid_to_run_as]\n"
 			"\t\t[-w url] [-R] [-V] [-h]\n"
 		        "\nNotes:\n\tNotify interval is in seconds. Default is 895 seconds.\n"
@@ -725,4 +748,7 @@
 	writepidfile(pidfilename, pid);
 
+	if (uid != (uid_t)-1 && setuid(uid) == -1)
+		err(EX_NOPERM, "setuid(%ld)", (long)uid);
+
 	return 0;
 }
@@ -841,4 +867,5 @@
 #endif
 	}
+#if defined(__linux__)
 	if( sqlite3_threadsafe() && sqlite3_libversion_number() >= 3005001 &&
 	    GETFLAG(INOTIFY_MASK) && pthread_create(&inotify_thread, NULL, start_inotify, NULL) )
@@ -846,4 +873,5 @@
 		DPRINTF(E_FATAL, L_GENERAL, "ERROR: pthread_create() failed for start_inotify.\n");
 	}
+#endif
 
 	sudp = OpenAndConfSSDPReceiveSocket(n_lan_addr, lan_addr);
