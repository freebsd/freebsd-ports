--- client/dhclient.c.orig	Thu Jan 25 09:18:06 2001
+++ client/dhclient.c	Fri Jan 26 06:15:50 2001
@@ -78,6 +78,7 @@
 u_int16_t remote_port;
 int no_daemon;
 int save_scripts;
+int onetry;
 
 static void usage PROTO ((void));
 
@@ -104,6 +105,7 @@
 	int no_dhclient_conf = 0;
 	int no_dhclient_db = 0;
 	int no_dhclient_pid = 0;
+	int no_dhclient_script = 0;
 	char *s;
 
 #ifdef SYSLOG_4_2
@@ -159,6 +161,11 @@
                                 usage ();
                         path_dhclient_db = argv [i];
 			no_dhclient_db = 1;
+                } else if (!strcmp (argv [i], "-sf")) {
+                        if (++i == argc)
+                                usage ();
+                        client_script_name = argv [i];
+			no_dhclient_script = 1;
 		} else if (!strcmp (argv [i], "-q")) {
 			quiet = 1;
 			quiet_interface_discovery = 1;
@@ -176,6 +183,8 @@
 		} else if (!strcmp (argv [i], "-w")) {
 			/* do not exit if there are no broadcast interfaces. */
 			persist = 1;
+		} else if (!strcmp (argv [i], "-1")) {
+			onetry = 1;
  		} else if (argv [i][0] == '-') {
  		    usage ();
  		} else {
@@ -208,6 +217,9 @@
 	if (!no_dhclient_pid && (s = getenv ("PATH_DHCLIENT_PID"))) {
 		path_dhclient_pid = s;
 	}
+	if (!no_dhclient_script && (s = getenv ("PATH_DHCLIENT_SCRIPT"))) {
+		client_script_name = s;
+	}
 
 	/* first kill of any currently running client */
 	if (release_mode) {
@@ -423,10 +435,11 @@
 	log_info (arr);
 	log_info (url);
 
-	log_error ("Usage: dhclient [-d] [-D] [-q] [-p <port>] %s",
+	log_error ("usage: dhclient [-1] [-d] [-D] [-q] [-p <port>] %s",
 		   "[-s server]");
-	log_fatal ("                [-lf lease-file] [-pf pid-file]%s",
-		   "[-cf config-file] [interface]");
+	log_error ("                [-cf config-file] [-lf lease-file] %s",
+		   "[-pf pid-file] [-sf script-file]");
+	log_fatal ("                [interface]");
 }
 
 isc_result_t find_class (struct class **c,
@@ -1432,6 +1445,10 @@
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
