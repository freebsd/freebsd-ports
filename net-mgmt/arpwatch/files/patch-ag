--- arpwatch.c.orig	Thu Jan 22 17:18:20 2004
+++ arpwatch.c	Thu Jul 20 12:30:08 2006
@@ -107,6 +107,8 @@
 
 char *prog;
 
+char *Watcher = NULL;
+
 int can_checkpoint;
 int swapped;
 int nobogons;
@@ -170,7 +172,7 @@
 	interface = NULL;
 	rfilename = NULL;
 	pd = NULL;
-	while ((op = getopt(argc, argv, "df:i:n:Nr:")) != EOF)
+	while ((op = getopt(argc, argv, "df:i:m:n:Nr:")) != EOF)
 		switch (op) {
 
 		case 'd':
@@ -202,6 +204,10 @@
 			rfilename = optarg;
 			break;
 
+		case 'm':
+			Watcher = optarg;
+			break;
+
 		default:
 			usage();
 		}
@@ -321,7 +327,6 @@
 
 	(void)setsignal(SIGINT, die);
 	(void)setsignal(SIGTERM, die);
-	(void)setsignal(SIGHUP, die);
 	if (rfilename == NULL) {
 		(void)setsignal(SIGQUIT, checkpoint);
 		(void)setsignal(SIGALRM, checkpoint);
@@ -751,6 +756,6 @@
 
 	(void)fprintf(stderr, "Version %s\n", version);
 	(void)fprintf(stderr, "usage: %s [-dN] [-f datafile] [-i interface]"
-	    " [-n net[/width]] [-r file]\n", prog);
+	    " [-m email] [-n net[/width]] [-r file]\n", prog);
 	exit(1);
 }
