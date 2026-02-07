--- main.cpp.orig	2011-06-01 07:45:51.000000000 -0400
+++ main.cpp	2011-06-01 07:46:28.000000000 -0400
@@ -35,7 +35,7 @@
 	struct stats *prev = NULL;
 	int n_prev = 0;
 	int c;
-	char *statuslog = "/usr/local/nagios/var/status.log";
+	char *statuslog = "/var/spool/nagios/status.dat";
 	int check_interval = 60;
 	char verbose = 0;
 	char is_20_format = 1;
@@ -110,7 +110,7 @@
 		}
 
 		if (is_file == 1)     /* file */
-			fd = open64(statuslog, O_RDONLY);
+			fd = open(statuslog, O_RDONLY);
 		else
 			fd = connect_to(statuslog);
 
