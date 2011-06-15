--- anna.cpp.orig	2011-01-18 05:39:10.000000000 -0500
+++ anna.cpp	2011-05-31 22:45:11.000000000 -0400
@@ -23,6 +23,7 @@
 #include "ssl.h"
 #include "log.h"
 }
+#include "anna.h"
 
 #define S_DISCONNECTED		1
 #define S_CONNECTED		2
@@ -43,6 +44,7 @@
 int minimum_time_for_successfull_login = 25; // one needs to be on-channel for at least 5 seconds to be considered a successfull login
 int join_timeout = 5;	// it should take no longer then 5 seconds to join a channel, otherwhise: abort connection and retry
 int max_n_join_tries = 2;	// try 2 times to get on a channel
+int throttle_delay = 1; // don't send more than one message per 1 seconds
 char *server = "localhost:6667";	/* default irc server */
 char *channel = "#nagircbot";	/* default channel to connect to */
 char *nick_prefix = "";   /* prefix text for all messages sent to channel */
@@ -53,7 +55,7 @@
 int one_line = 1;
 char *username = "Nagios IRC Bot " VERSION ", (C) www.vanheusden.com";	/* complete username */
 int verbose = 255;		/* default is log everything */
-char *statuslog = "/usr/local/nagios/var/status.log";
+char *statuslog = "/var/spool/nagios/status.dat";
 int statuslog_version = 2;
 int statuslog_location = L_FILE;
 char use_colors = 0;
@@ -174,6 +176,13 @@
 
 int irc_privmsg(server_t server_conn, char *channel, char *msg)
 {
+	static time_t last_msg = time(NULL);
+	time_t diff = time(NULL) - last_msg;
+	if (diff < throttle_delay) {
+		sleep(throttle_delay - diff);
+	}
+	time(&last_msg);
+
 	return send_irc(server_conn, "PRIVMSG %s :%s", channel, msg);
 }
 
@@ -192,7 +201,7 @@
 
 		/* open file or connection to nagios status socket */
 		if (is_file == 1)     /* file */
-			fd = open64(statuslog, O_RDONLY);
+			fd = open(statuslog, O_RDONLY);
 		else
 			fd = connect_to(statuslog);
 		if (fd == -1)
@@ -490,7 +499,7 @@
 	if (verbose > 1) dolog("reload_statuslog started");
 
 	if (statuslog_location == L_FILE)     /* file */
-		fd_sl = open64(statuslog, O_RDONLY);
+		fd_sl = open(statuslog, O_RDONLY);
 	else
 		fd_sl = connect_to(statuslog);
 
