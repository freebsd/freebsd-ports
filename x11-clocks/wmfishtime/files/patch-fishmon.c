--- fishmon.c.orig	Sun May 27 05:53:09 2001
+++ fishmon.c	Mon Jul  7 04:01:52 2003
@@ -1018,26 +1018,28 @@
 {
     static int ch = 0;
     static struct option long_opts[] = {
-	{ "h",		no_argument, NULL, 1 },
-	{ "help",	no_argument, NULL, 1 },
-	{ "v",		no_argument, NULL, 2 },
-	{ "version",	no_argument, NULL, 2 },
-	{ "c",		no_argument, &enable_check_mail, 1 },
-	{ "check-mail", no_argument, &enable_check_mail, 1 },
-	{ "b",		no_argument, &broken_wm, 1 },
-	{ "broken",	no_argument, &broken_wm, 1 },
+	{ "help",	no_argument, NULL, 'h' },
+	{ "version",	no_argument, NULL, 'v' },
+	{ "check-mail", no_argument, &enable_check_mail, 'c' },
+	{ "broken",	no_argument, &broken_wm, 'b' },
 	{ 0, 0, 0, 0 }
     };
 
-    while ((ch = getopt_long_only(argc, argv, "", long_opts, NULL)) != -1) {
+    while ((ch = getopt_long(argc, argv, "hvcb", long_opts, NULL)) != -1) {
 	switch (ch) {
-	    case 1:
+	    case 'h':
 		do_help();
 		exit(0);
 		break;
-	    case 2:
+	    case 'v':
 		do_version();
 		exit(0);
+		break;
+	    case 'c':
+		enable_check_mail = 1;
+		break;
+	    case 'b':
+		broken_wm = 1;
 		break;
 	}
     }
