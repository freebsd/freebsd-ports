--- nc.cpp.orig	2017-12-27 12:07:16 UTC
+++ nc.cpp
@@ -178,7 +178,7 @@ void help(void)
 
 	printf("-f file   what file to monitor (usuallly:\n");
 	printf("-F host:port   connect to a host for retrieving the status.log information\n");
-	printf("          /usr/local/nagios/var/status.log, look for status_file in\n");
+	printf("          /var/spool/nagios/status.log, look for status_file in\n");
 	printf("          the nagios.cfg file\n");
 	printf("-i x      check interval (in seconds)\n");
 	printf("-a        list also the services for hosts that are down\n");
@@ -210,7 +210,7 @@ int main(int argc, char *argv[])
 	WINDOW *win;
 	int sw;
 
-	char *status_log = "/usr/local/nagios/var/status.log";
+	char *status_log = "/var/spool/nagios/status.log";
 	int interval = 5;
 	char list_all_problems = 0;
 	char always_notify = 0;
@@ -322,7 +322,7 @@ int main(int argc, char *argv[])
 		wattroff(win, COLOR_PAIR(MY_DRAW));
 
 		if (file_mode == 0)	/* file */
-			fd = open64(status_log, O_RDONLY);
+			fd = open(status_log, O_RDONLY);
 		else
 			fd = connect_to(status_log);
 
