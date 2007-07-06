--- anna.cpp.orig	Mon Nov 27 06:21:58 2006
+++ anna.cpp	Sat Apr 28 19:27:02 2007
@@ -12,6 +12,8 @@
 #include <stdlib.h>
 #include <signal.h>
 #include <pwd.h>
+#include <sys/param.h>
+#include <libutil.h>
 
 #include "utils.h"
 #include "pl.h"
@@ -19,6 +21,7 @@
 #include "error.h"
 #include "log.h"
 }
+#include "anna.h"
 
 #define S_DISCONNECTED		1
 #define S_CONNECTED		2
@@ -39,6 +42,7 @@
 int minimum_time_for_successfull_login = 25; // one needs to be on-channel for at least 5 seconds to be considered a successfull login
 int join_timeout = 5;	// it should take no longer then 5 seconds to join a channel, otherwhise: abort connection and retry
 int max_n_join_tries = 2;	// try 2 times to get on a channel
+int throttle_delay = 1; // don't send more than one message per 1 seconds
 char *server = "localhost:6667";	/* default irc server */
 char *channel = "#nagircbot";	/* default channel to connect to */
 char *nick = "nagircbot";
@@ -56,7 +60,7 @@
 int max_time_last_host_update = 300, max_time_oldest_host_update = 3600, max_time_last_host_check = 300, max_time_oldest_host_check = 3 * 86400, max_time_last_service_check = 20 * 60, max_time_oldest_service_check = 3 * 86400, max_time_oldest_next_service_check = 20 * 60;
 
 char *state_str[4] = { " OK ", "WARN", "CRIT", " ?? " };
-char *color_str[4] = { mystrdup("_3,1 "), mystrdup("_8,1 "), mystrdup("_4,1 "), mystrdup("_11,1 ") }; /* FIXME */
+char *color_str[4] = { mystrdup("_9,1 "), mystrdup("_8,1 "), mystrdup("_4,1 "), mystrdup("_11,1 ") }; /* FIXME */
 struct stats *prev = NULL;
 int n_prev = 0;
 char topic[4096] = { 0 };
@@ -105,13 +109,18 @@
 	if (irc_set_nick(fd, nick) == -1)
 		return -1;
 
+    /* "Currently this requires that clients send a PASS command before sending
+     * the NICK/USER combination and servers *must* send a PASS command before
+     * any SERVER command." */
+	if (password != NULL) {
+        if (send_irc(fd, "PASS %s", password) == -1)
+			return -1;
+	}
+
 	/* FIXME: localhost must be, ehr, local host */
 	if (send_irc(fd, "USER %s \"localhost\" \"%s\" :%s", user, server, username) == -1)
 		return -1;
 
-	if (password != NULL && send_irc(fd, "PASS %s", password) == -1)
-		return -1;
-
 	return 0;
 }
 
@@ -153,6 +162,12 @@
 
 int irc_privmsg(int fd, char *channel, char *msg)
 {
+    static time_t last_msg = time(NULL);
+    time_t diff = time(NULL) - last_msg;
+    if (diff < throttle_delay) {
+            sleep(throttle_delay - diff);
+    }
+    time(&last_msg);
 	return send_irc(fd, "PRIVMSG %s :%s", channel, msg);
 }
 
@@ -166,7 +181,7 @@
 
 		/* open file or connection to nagios status socket */
 		if (is_file == 1)     /* file */
-			fd = open64(statuslog, O_RDONLY);
+			fd = open(statuslog, O_RDONLY);
 		else
 			fd = connect_to(statuslog);
 		if (fd == -1)
@@ -416,7 +431,7 @@
 	if (verbose > 1) dolog("reload_statuslog started");
 
 	if (statuslog_location == L_FILE)     /* file */
-		fd_sl = open64(statuslog, O_RDONLY);
+		fd_sl = open(statuslog, O_RDONLY);
 	else
 		fd_sl = connect_to(statuslog);
 
@@ -712,6 +727,7 @@
 	printf("-z user	user to run as\n");
 	printf("-H     show only state type 'HARD' (default)\n");
 	printf("-S     show also state type 'SOFT'\n");
+	printf("-P file store the pid in a file\n");
 }
 
 int main(int argc, char *argv[])
@@ -724,14 +740,19 @@
 	time_t time_join_channel_started = (time_t)0;
 	time_t time_tcp_connected = (time_t)0;
 	int join_tries = 0;
-	char *runas = NULL;
+	char *runas = NULL, *pidfile = NULL;
+     	pid_t otherpid;
+
 
 	color_str[0][0] = color_str[1][0] = color_str[2][0] = color_str[3][0] = 3;
 
-	while((c = getopt(argc, argv, "xXF:f:i:hHSs:c:Ctn:u:U:p:T:mvdVz:")) != -1)
+	while((c = getopt(argc, argv, "xXP:F:f:i:hHSs:c:Ctn:u:U:p:T:mvdVz:")) != -1)
 	{
 		switch(c)
 		{
+			case 'P':
+				pidfile = optarg;
+				break;
 			case 'z':
 				runas = optarg;
 				break;
@@ -867,6 +888,14 @@
 		}
 	}
 
+     pfh = pidfile_open(pidfile, 0600, &otherpid);
+     if (pfh == NULL) {
+             if (errno == EEXIST)
+                     error_exit("Daemon already running, pid: %d.", otherpid);
+             /* If we cannot create pidfile from other reasons, only warn. */
+             dolog("Cannot open or create pidfile");
+     }
+
 	if (do_fork)
 	{
 		if (daemon(0, 0) == -1)
@@ -875,6 +904,9 @@
 		}
 	}
 
+     pidfile_write(pfh);
+
+
 	signal(SIGPIPE, SIG_IGN);
 
 	for(;;)
@@ -1056,5 +1088,6 @@
 		}
 	}
 
+	pidfile_remove(pfh);
 	return 0;
 }
