--- arpwatch.c.orig	2019-11-30 18:35:23 UTC
+++ arpwatch.c
@@ -198,7 +198,7 @@ main(int argc, char **argv)
 	interface = NULL;
 	rfilename = NULL;
 	pd = NULL;
-	while ((op = getopt(argc, argv, "CdD:Ff:i:n:NpP:qr:svw:W:x:zZ")) != EOF)
+	while ((op = getopt(argc, argv, "CdD:Ff:i:m:n:NpP:qr:svw:W:x:zZ")) != EOF)
 		switch (op) {
 
 		case 'C':
@@ -262,6 +262,10 @@ main(int argc, char **argv)
 			++vrrpflag;
 			break;
 
+		case 'm':
+			fprintf(stderr, "%s: WARNING: -m is deprecated,"
+			    " please use -w instead\n", prog);
+			/* fallthrough */
 		case 'w':
 			watcher = optarg;
 			break;
