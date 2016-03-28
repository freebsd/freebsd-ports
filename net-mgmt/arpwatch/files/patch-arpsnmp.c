--- arpsnmp.c.orig	2004-01-22 22:25:17 UTC
+++ arpsnmp.c
@@ -68,6 +68,8 @@ __dead	void usage(void) __attribute__((v
 
 char *prog;
 
+char *Watcher;
+
 extern int optind;
 extern int opterr;
 extern char *optarg;
@@ -90,7 +92,7 @@ main(int argc, char **argv)
 	}
 
 	opterr = 0;
-	while ((op = getopt(argc, argv, "df:")) != EOF)
+	while ((op = getopt(argc, argv, "df:m:")) != EOF)
 		switch (op) {
 
 		case 'd':
@@ -105,6 +107,10 @@ main(int argc, char **argv)
 			arpfile = optarg;
 			break;
 
+		case 'm':
+			Watcher = optarg;
+			break;
+
 		default:
 			usage();
 		}
@@ -185,6 +191,6 @@ usage(void)
 
 	(void)fprintf(stderr, "Version %s\n", version);
 	(void)fprintf(stderr,
-	    "usage: %s [-d] [-f datafile] file [...]\n", prog);
+	    "usage: %s [-d] [-f datafile] [-m email] file [...]\n", prog);
 	exit(1);
 }
