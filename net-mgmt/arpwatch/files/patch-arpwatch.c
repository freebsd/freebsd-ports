--- arpwatch.c.orig	2004-01-22 22:18:20 UTC
+++ arpwatch.c
@@ -107,6 +107,8 @@ struct rtentry;
 
 char *prog;
 
+char *Watcher = NULL;
+
 int can_checkpoint;
 int swapped;
 int nobogons;
@@ -170,7 +172,7 @@ main(int argc, char **argv)
 	interface = NULL;
 	rfilename = NULL;
 	pd = NULL;
-	while ((op = getopt(argc, argv, "df:i:n:Nr:")) != EOF)
+	while ((op = getopt(argc, argv, "dzf:i:m:n:Nr:")) != EOF)
 		switch (op) {
 
 		case 'd':
@@ -202,6 +204,13 @@ main(int argc, char **argv)
 			rfilename = optarg;
 			break;
 
+		case 'm':
+			Watcher = optarg;
+			break;
+		case 'z':
+			zeroflag = 1;
+			break;
+
 		default:
 			usage();
 		}
@@ -321,7 +330,6 @@ main(int argc, char **argv)
 
 	(void)setsignal(SIGINT, die);
 	(void)setsignal(SIGTERM, die);
-	(void)setsignal(SIGHUP, die);
 	if (rfilename == NULL) {
 		(void)setsignal(SIGQUIT, checkpoint);
 		(void)setsignal(SIGALRM, checkpoint);
@@ -751,6 +759,6 @@ usage(void)
 
 	(void)fprintf(stderr, "Version %s\n", version);
 	(void)fprintf(stderr, "usage: %s [-dN] [-f datafile] [-i interface]"
-	    " [-n net[/width]] [-r file]\n", prog);
+	    " [-m email] [-n net[/width]] [-r file]\n", prog);
 	exit(1);
 }
