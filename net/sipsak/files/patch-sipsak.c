--- sipsak.c.orig	Fri Oct  8 20:07:14 2004
+++ sipsak.c	Tue Oct 26 15:55:19 2004
@@ -207,6 +207,9 @@
 	char	buff[BUFSIZE];
 	int		length, c, i, j;
 	char	*delim, *delim2;
+	pid_t pid;
+	struct timespec ts;
+	int upp;
 #ifdef HAVE_GETOPT_LONG
 	int option_index = 0;
 	static struct option l_opts[] = {
@@ -269,9 +272,6 @@
 	memset(ack, 0, BUFSIZE);
 	memset(fqdn, 0, FQDN_SIZE);
 	memset(messusern, 0, FQDN_SIZE);
-	pid_t pid;
-	struct timespec ts;
-	int upp;
 
 	if (argc==1) print_help();
 
@@ -354,7 +354,7 @@
 				flood=1;
 				break;
 			case 'f':
-				if strncmp(optarg, "-", 1) {
+				if (strncmp(optarg, "-", 1)) {
 					/* file is opened in binary mode so that the cr-lf is 
 					   preserved */
 					pf = fopen(optarg, "rb");
