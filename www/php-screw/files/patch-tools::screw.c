--- tools/screw.c.orig	Sun Aug 31 00:55:45 2003
+++ tools/screw.c	Sun Aug 31 00:56:14 2003
@@ -18,12 +18,12 @@

 	if (argc != 2) {
 		fprintf(stderr, "Usage: filename.\n");
-		exit();
+		exit(1);
 	}
 	fp = fopen(argv[1], "r");
 	if (fp == NULL) {
 		fprintf(stderr, "File not found(%s)\n", argv[1]);
-		exit();
+		exit(1);
 	}

 	fstat(fileno(fp), &stat_buf);
@@ -36,13 +36,13 @@

 	if (memcmp(datap, PM9SCREW, PM9SCREW_LEN) == 0) {
 		fprintf(stderr, "Already Crypted(%s)\n", argv[1]);
-		exit();
+		exit(1);
 	}

 	fp = fopen(oldfilename, "w");
 	if (fp == NULL) {
 		fprintf(stderr, "Can not create backup file(%s)\n", oldfilename);
-		exit();
+			exit(1);
 	}
 	fwrite(datap, datalen, 1, fp);
 	fclose(fp);
@@ -56,7 +56,7 @@
 	fp = fopen(argv[1], "w");
 	if (fp == NULL) {
 		fprintf(stderr, "Can not create crypt file(%s)\n", oldfilename);
-		exit();
+		exit(1);
 	}
 	fwrite(PM9SCREW, PM9SCREW_LEN, 1, fp);
 	fwrite(newdatap, newdatalen, 1, fp);
