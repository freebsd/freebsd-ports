--- pptpd.c.orig	Fri Oct 21 12:10:41 2005
+++ pptpd.c	Fri Oct 21 12:12:30 2005
@@ -109,13 +109,13 @@
 	printf("                           (default is /etc/ppp/options).\n");
 #endif
 	printf(" [-p] [--pidfile file]     Specifies the file to write the process ID to\n");
-	printf("                           (default is /var/run/pptpd.pid).\n");
+	printf("                           (default is %s).\n",PIDFILE_DEFAULT);
 #if !defined(BSDUSER_PPP)
 	printf(" [-s] [--speed baud]       Specifies the baud speed for the PPP daemon\n");
-	printf("                           (default is 115200).\n");
+	printf("                           (default is %s).\n",PPP_SPEED_DEFAULT);
 #endif
 	printf(" [-t] [--stimeout seconds] Specifies the timeout for the first packet. This is a DOS protection\n");
-	printf("                           (default is 10).\n");
+	printf("                           (default is %s).\n",STIMEOUT_DEFAULT);
 	printf(" [-v] [--version]          Displays the pptpd version number.\n");
 	printf(" [-w] [--logwtmp]          Update wtmp as users login.\n");
 
