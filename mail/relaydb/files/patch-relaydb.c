--- relaydb.c.orig	Sun Dec 14 15:59:30 2003
+++ relaydb.c	Tue Dec 16 18:58:52 2003
@@ -47,6 +47,11 @@
 	time_t	 mtime;
 };
 
+struct old_data {
+	int	 white;
+	int	 black;
+};
+
 extern char	*__progname;
 const int	 bufsiz = 1024;
 const int	 factor = 3;
@@ -318,7 +323,8 @@
 			if (d.mtime >= mtime)
 				continue;
 			if (debug)
-				printf("touching %u %s\n", mtime, address);
+				printf("touching %lu %s\n", 
+					(unsigned long)mtime, address);
 			d.mtime = mtime;
 			memset(&dbk, 0, sizeof(dbk));
 			dbk.size = strlen(address);
@@ -349,6 +355,7 @@
 	int		 pos = 0, r;
 	struct data	 d;
 	unsigned	 count = 0;
+	unsigned long	 time_read;
 
 	if (debug)
 		printf("importing %s\n", filename);
@@ -364,8 +371,8 @@
 			buf[pos] = 0;
 			pos = 0;
 
-			r = sscanf(buf, "%127s %d %d %u", address,
-			    &d.white, &d.black, &d.mtime);
+			r = sscanf(buf, "%127s %d %d %lu", address,
+			    &d.white, &d.black, &time_read);
 			if (r == 3)
 				d.mtime = time(NULL);
 			else if (r != 4) {
@@ -373,14 +380,16 @@
 				    buf);
 				fclose(f);
 				return;
-			}
+			} else
+				d.mtime = time_read;
 			if (!((use_v4 && address_valid_v4(address)) ||
 			    (use_v6 && address_valid_v6(address))) ||
 			    address_private(address))
 				continue;
 			if (debug)
-				printf("adding %s %d %d %u\n",
-				    address, d.white, d.black, d.mtime);
+				printf("adding %s %d %d %lu\n",
+				    address, d.white, d.black, 
+				    (unsigned long)d.mtime);
 			memset(&dbk, 0, sizeof(dbk));
 			dbk.size = strlen(address);
 			dbk.data = address;
@@ -405,7 +414,7 @@
 void
 usage()
 {
-	fprintf(stderr, "usage: %s [-46bdlnrvw] "
+	fprintf(stderr, "usage: %s [-46bdlnOrvw] "
 	    "[-BW [+-]num] [-m [+-]days]\n\t[-f filename] "
 	    "[-i filename] [-t filename]\n", __progname);
 	exit(1);
@@ -414,7 +423,7 @@
 int
 main(int argc, char *argv[])
 {
-	int		 list = 0, delete = 0;
+	int		 list = 0, delete = 0, old_list = 0;
 	const char	*filename = NULL, *import = NULL, *syslog = NULL;
 	time_t		 mtime = 0;
 	int		 mtime_op = 0;
@@ -423,7 +432,7 @@
 	int		 ch;
 	unsigned	 count = 0;
 
-	while ((ch = getopt(argc, argv, "46bB:df:i:lm:nrt:vwW:")) != -1) {
+	while ((ch = getopt(argc, argv, "46bB:df:i:lm:nOrt:vwW:")) != -1) {
 		switch (ch) {
 		case '4':
 			use_v4 = 1;
@@ -482,6 +491,9 @@
 		case 'n':
 			traverse = 0;
 			break;
+		case 'O':
+			old_list = 1;
+			break;
 		case 'r':
 			reverse = 1;
 			break;
@@ -496,9 +508,14 @@
 		}
 	}
 
-	if (!list && !delete && !action && import == NULL && syslog == NULL)
+	if (!old_list && !list && !delete && !action && import == NULL && syslog == NULL)
 		usage();
 
+	if (old_list && (list || delete)) {
+		fprintf(stderr, "-O is incompatible with -l and -d\n");
+		return (1);
+	}
+
 	if (delete && !action && !mtime && black == -1 && white == -1) {
 		fprintf(stderr, "to delete all entries, delete the file\n");
 		return (1);
@@ -583,8 +600,9 @@
 				continue;
 			if (list) {
 				if (debug)
-					printf("%s %d %d %u\n",
-					    a, d.white, d.black, d.mtime);
+					printf("%s %d %d %lu\n",
+					    a, d.white, d.black, 
+						(unsigned long)d.mtime);
 				else
 					printf("%s\n", a);
 			} else {
@@ -600,6 +618,40 @@
 				count++;
 			}
 		}
+	} else if (old_list) {
+		int		 r;
+		struct old_data	 d;
+		char		 a[128];
+
+		memset(&dbk, 0, sizeof(dbk));
+		memset(&dbd, 0, sizeof(dbd));
+		r = db->seq(db, &dbk, &dbd, R_FIRST);
+		while (!r) {
+			if (dbk.size < 1 || dbk.size >= sizeof(a)||
+			    dbd.size != sizeof(struct old_data)) {
+				fprintf(stderr, "db->seq() invalid data\n");
+				if (db->close(db))
+					fprintf(stderr, "db->close() %s\n",
+					    strerror(errno));
+				return (1);
+			}
+			memcpy(&d, dbd.data, sizeof(d));
+			if (!action ||
+			    (action == 'b' && d.black >  factor * d.white) ||
+			    (action == 'w' && d.black <= factor * d.white)) {
+				memcpy(a, dbk.data, dbk.size);
+				a[dbk.size] = 0;
+				if ((use_v4 && address_valid_v4(a)) ||
+				    (use_v6 && address_valid_v6(a))) {
+					if (debug)
+						printf("%s %d %d\n",
+						    a, d.white, d.black);
+					else
+						printf("%s\n", a);
+				}
+			}
+			r = db->seq(db, &dbk, &dbd, R_NEXT);
+		}
 	} else {
 		if (debug)
 			printf("reading mail headers, considering the mail "
@@ -609,7 +661,7 @@
 	if (delete && !list)
 		printf("%u entries deleted\n", count);
 
-	if (!list && db->sync(db, 0))
+	if (!old_list && !list && db->sync(db, 0))
 		fprintf(stderr, "db->sync() %s\n", strerror(errno));
 	if (db->close(db))
 		fprintf(stderr, "db->close() %s\n", strerror(errno));
