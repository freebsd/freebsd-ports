--- client/dhclient.c.orig	Thu Feb 15 23:17:05 2001
+++ client/dhclient.c	Fri Mar  2 05:51:43 2001
@@ -78,6 +78,7 @@
 u_int16_t remote_port;
 int no_daemon;
 int save_scripts;
+int onetry;
 struct string_list *client_env;
 int client_env_count;
 
@@ -106,6 +107,7 @@
 	int no_dhclient_conf = 0;
 	int no_dhclient_db = 0;
 	int no_dhclient_pid = 0;
+	int no_dhclient_script = 0;
 	char *s;
 
 #ifdef SYSLOG_4_2
@@ -161,6 +163,13 @@
                                 usage ();
                         path_dhclient_db = argv [i];
 			no_dhclient_db = 1;
+                } else if (!strcmp (argv [i], "-sf")) {
+                        if (++i == argc)
+                                usage ();
+                        client_script_name = argv [i];
+			no_dhclient_script = 1;
+		} else if (!strcmp (argv [i], "-1")) {
+			onetry = 1;
 		} else if (!strcmp (argv [i], "-q")) {
 			quiet = 1;
 			quiet_interface_discovery = 1;
@@ -224,6 +233,9 @@
 	if (!no_dhclient_pid && (s = getenv ("PATH_DHCLIENT_PID"))) {
 		path_dhclient_pid = s;
 	}
+	if (!no_dhclient_script && (s = getenv ("PATH_DHCLIENT_SCRIPT"))) {
+		client_script_name = s;
+	}
 
 	/* first kill of any currently running client */
 	if (release_mode) {
@@ -445,10 +457,12 @@
 	log_info (arr);
 	log_info (url);
 
-	log_error ("Usage: dhclient [-d] [-D] [-q] [-p <port>] %s",
+	log_error ("Usage: dhclient [-1] [-d] [-D] [-q] [-p <port>] %s",
 		   "[-s server]");
-	log_fatal ("                [-lf lease-file] [-pf pid-file]%s",
-		   "[-cf config-file] [interface] [-e VAR=val]");
+	log_error ("                [-cf config-file] [-lf lease-file] %s",
+		   "[-pf pid-file]");
+	log_fatal ("                [-sf script-file] [interface] %s",
+		   "[-e VAR=val]");
 }
 
 isc_result_t find_class (struct class **c,
@@ -1453,6 +1467,10 @@
 	/* No leases were available, or what was available didn't work, so
 	   tell the shell script that we failed to allocate an address,
 	   and try again later. */
+	if (onetry) {
+		exit(2);
+		log_info ("Unable to obtain a lease on first try - exiting.\n");
+	}
 	log_info ("No working leases in persistent database - sleeping.");
 	script_init (client, "FAIL", (struct string_list *)0);
 	if (client -> alias)
