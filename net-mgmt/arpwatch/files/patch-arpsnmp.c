--- arpsnmp.c.orig	Mon Jan 18 01:47:40 1999
+++ arpsnmp.c	Thu Feb 22 22:47:29 2001
@@ -68,6 +68,8 @@
 
 char *prog;
 
+char *Watcher;
+
 extern int optind;
 extern int opterr;
 extern char *optarg;
@@ -90,7 +92,7 @@
 	}
 
 	opterr = 0;
-	while ((op = getopt(argc, argv, "df:")) != EOF)
+	while ((op = getopt(argc, argv, "df:m:")) != EOF)
 		switch (op) {
 
 		case 'd':
@@ -105,6 +107,10 @@
 			arpfile = optarg;
 			break;
 
+		case 'm':
+			Watcher = optarg;
+			break;
+
 		default:
 			usage();
 		}
@@ -184,6 +190,6 @@
 
 	(void)fprintf(stderr, "Version %s\n", version);
 	(void)fprintf(stderr,
-	    "usage: %s [-d] [-f datafile] file [...]\n", prog);
+	    "usage: %s [-d] [-f datafile] [-m email] file [...]\n", prog);
 	exit(1);
 }
