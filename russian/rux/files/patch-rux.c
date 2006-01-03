--- rux.c.orig	Sun Dec 25 00:22:01 2005
+++ rux.c	Sun Jan  1 15:46:52 2006
@@ -70,9 +70,10 @@
 	extern int optind;
 
 	char *buf = NULL;		/* analizing buffer */
+	int flag;	
+	int readstdin = 0;              /* read from stdin */
 
 	o_cp = &codepage[2];		/* sets koi8-r as default outcp */
-	int flag;
 
 	while ((flag = getopt(argc, argv, "i:o:thegTs:")) != -1) {
 		switch (flag) {
@@ -133,19 +134,18 @@
 		}
 	}
 
-	int readstdin = 0;		/* read from stdin */
-
 	if (argc == 0)
 		readstdin = 1;
 
 	while (1) {
+		int buflen = 0;
+
 		if (readstdin) {
 			in = stdin;
 		} else if ((in = fopen(*argv, "r")) == NULL) {
 			perror(*argv);
 			return errno;
 		}
-		int buflen = 0;
 
 		if (fdetect) {
 			buflen = fread(buf, 1, ansize, in);
