--- arpsnmp.c.orig	2019-11-30 18:35:23 UTC
+++ arpsnmp.c
@@ -104,7 +104,7 @@ main(int argc, char **argv)
 	}
 
 	opterr = 0;
-	while ((op = getopt(argc, argv, "CdD:f:qsw:W:Z")) != EOF)
+	while ((op = getopt(argc, argv, "CdD:f:m:qsw:W:Z")) != EOF)
 		switch (op) {
 
 		case 'C':
@@ -135,6 +135,10 @@ main(int argc, char **argv)
 			++suppress;
 			break;
 
+		case 'm':
+			fprintf(stderr, "%s: WARNING: -m is deprecated,"
+			    " please use -w instead\n", prog);
+			/* fallthrough */
 		case 'w':
 			watcher = optarg;
 			break;
