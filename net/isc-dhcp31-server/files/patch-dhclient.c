--- client/dhclient.c.orig	Wed Jul 19 23:13:11 2000
+++ client/dhclient.c	Sun Aug  6 20:43:14 2000
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
@@ -1239,6 +1242,10 @@
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
@@ -2157,7 +2164,7 @@
 
 int dhcp_option_ev_name (buf, buflen, option)
 	char *buf;
-	unsigned buflen;
+	size_t buflen;
 	struct option *option;
 {
 	int i;
