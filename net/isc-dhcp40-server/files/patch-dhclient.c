--- client/dhclient.c.orig	Thu Sep 14 05:42:01 2000
+++ client/dhclient.c	Wed Sep 27 03:31:33 2000
@@ -78,6 +78,7 @@
 u_int16_t remote_port;
 int no_daemon;
 int save_scripts;
+int onetry;
 
 static void usage PROTO ((void));
 
@@ -176,6 +177,8 @@
 		} else if (!strcmp (argv [i], "-w")) {
 			/* do not exit if there are no broadcast interfaces. */
 			persist = 1;
+		} else if (!strcmp (argv [i], "-1")) {
+			onetry = 1;
  		} else if (argv [i][0] == '-') {
  		    usage ();
  		} else {
@@ -417,7 +420,7 @@
 	log_info (arr);
 	log_info (url);
 
-	log_error ("Usage: dhclient [-d] [-D] [-q] [-p <port>] %s",
+	log_error ("Usage: dhclient [-1] [-d] [-D] [-q] [-p <port>] %s",
 		   "[-s server]");
 	log_fatal ("                [-lf lease-file] [-pf pid-file]%s",
 		   "[-cf config-file] [interface]");
@@ -1402,6 +1405,10 @@
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
