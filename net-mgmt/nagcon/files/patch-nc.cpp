--- ./nc.cpp.orig	Tue Mar 28 20:58:16 2006
+++ ./nc.cpp	Wed Mar 29 20:39:15 2006
@@ -182,7 +182,7 @@
 	version();
 
 	printf("-f file   what file to monitor (usuallly:\n");
-	printf("          /usr/local/nagios/var/status.log, look for status_file in\n");
+	printf("          /var/spool/nagios/status.dat, look for status_file in\n");
 	printf("          the nagios.cfg file\n");
 	printf("-i x      check interval (in seconds)\n");
 	printf("-a        list also the services for hosts that are down\n");
@@ -208,7 +208,7 @@
 	WINDOW *win;
 	int sw;
 
-	char *statuslog = "/usr/local/nagios/var/status.log";
+	char *statuslog = "/var/spool/nagios/status.dat";
 	int interval = 5;
 	char list_all_problems = 0;
 	char always_notify = 0;
