--- client/dhclient.c.orig	Wed May 10 02:34:28 2000
+++ client/dhclient.c	Wed May 10 02:34:49 2000
@@ -64,6 +64,7 @@
 int log_priority;
 int no_daemon;
 int save_scripts;
+int onetry;
 
 static void usage PROTO ((void));
 
@@ -120,6 +121,8 @@
 			if (++i == argc)
 				usage ();
 			server = argv [i];
+		} else if (!strcmp (argv [i], "-1")) {
+			onetry = 1;
  		} else if (argv [i][0] == '-') {
  		    usage ();
  		} else {
@@ -273,7 +276,7 @@
 
 static void usage ()
 {
-	log_error ("Usage: dhclient [-d] [-D] [-q] [-p <port>] %s",
+	log_error ("Usage: dhclient [-d] [-D] [-q] [-1] [-p <port>] %s",
 		   "[-s server]");
 	log_error ("                [-lf lease-file] [-pf pid-file]%s",
 		   "[-cf config-file] [interface]");
@@ -1232,6 +1235,10 @@
 	/* No leases were available, or what was available didn't work, so
 	   tell the shell script that we failed to allocate an address,
 	   and try again later. */
+	if (onetry) {
+		exit(2);
+		log_info ("Unable to obtain a lease on first try - exiting.\n");
+	}
 	log_info ("No working leases in persistent database - sleeping.\n");
 	script_init (client, "FAIL", (struct string_list *)0);
 	if (client -> alias)
