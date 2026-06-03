--- mkCTM/mkctm.c.ORI	2023-12-24 08:03:42.335824000 +0100
+++ mkCTM/mkctm.c	2023-12-24 08:04:21.959999000 +0100
@@ -42,7 +42,7 @@
 int	damage, damage_limit;
 int	change;
 
-FILE	*logf;
+FILE	*logfile;
 
 u_long s1_ignored,	s2_ignored;
 u_long s1_bogus,	s2_bogus;
@@ -134,7 +134,7 @@
 	printf("%s %s%s %u %u %o", 
 	    pfx, name, de->d_name, 
 	    st->st_uid, st->st_gid, st->st_mode & ~S_IFMT);
-	fprintf(logf, "%s %s%s\n", pfx, name, de->d_name);
+	fprintf(logfile, "%s %s%s\n", pfx, name, de->d_name);
 	if (verbose > 1) {
 		fprintf(stderr, "%s %s%s\n", pfx, name, de->d_name);
 	}
@@ -362,7 +362,7 @@
 		strcpy(p, name);  strcat(p, de->d_name); strcat(p, "/");
 		DoDir(dir1, dir2, p);
 		printf("CTMDR %s%s\n", name, de->d_name);
-		fprintf(logf, "CTMDR %s%s\n", name, de->d_name);
+		fprintf(logfile, "CTMDR %s%s\n", name, de->d_name);
 		if (verbose > 1) {
 			fprintf(stderr, "CTMDR %s%s\n", name, de->d_name);
 		}
@@ -376,7 +376,7 @@
 			strcat(buf1, "/"); strcat(buf1, de->d_name);
 		m1 = MD5File(buf1, md5_1);
 		printf("CTMFR %s%s %s\n", name, de->d_name, m1);
-		fprintf(logf, "CTMFR %s%s %s\n", name, de->d_name, m1);
+		fprintf(logfile, "CTMFR %s%s %s\n", name, de->d_name, m1);
 		if (verbose > 1) {
 			fprintf(stderr, "CTMFR %s%s\n", name, de->d_name);
 		}
@@ -403,14 +403,14 @@
 			if (flag_ignore && 
 			    !regexec(&reg_ignore, buf1, 0, 0, 0)) {
 				(*ignored)++;
-				fprintf(logf, "Ignore %s\n", buf1);
+				fprintf(logfile, "Ignore %s\n", buf1);
 				if (verbose > 2) {
 					fprintf(stderr, "Ignore %s\n", buf1);
 				}
 			} else if (flag_bogus && 
 			    !regexec(&reg_bogus, buf1, 0, 0, 0)) {
 				(*bogus)++;
-				fprintf(logf, "Bogus %s\n", buf1);
+				fprintf(logfile, "Bogus %s\n", buf1);
 				fprintf(stderr, "Bogus %s\n", buf1);
 				damage++;
 			} else {
@@ -524,8 +524,8 @@
 	strcpy(tmpfilename, tmpdir); strcat(tmpfilename, tmpfilebase);
 	mktemp(tmpfilename);
 
-	snprintf(command,command_size,"tar -C %s -cvf %s %s 2>&%d\n",dir2,tmpfilename,de->d_name,fileno(logf));
-	fflush(logf);
+	snprintf(command,command_size,"tar -C %s -cvf %s %s 2>&%d\n",dir2,tmpfilename,de->d_name,fileno(logfile));
+	fflush(logfile);
 	ret_val = system(command);
 	if (ret_val!=0) errx(1,"The command \"%s\" failed with return value %d",command,ret_val);
 	printf("CTMTR ");
@@ -576,8 +576,8 @@
 		errx(1,"No db/release in %s",buf2);
 
 	if (release2 > release1) {
-		snprintf(command,command_size,"svnadmin dump %s/%s -r %ld:%ld --incremental --deltas 2>&%d > %s\n",dir2,de->d_name,release1+1,release2,fileno(logf),tmpfilename);
-		fflush(logf);
+		snprintf(command,command_size,"svnadmin dump %s/%s -r %ld:%ld --incremental --deltas 2>&%d > %s\n",dir2,de->d_name,release1+1,release2,fileno(logfile),tmpfilename);
+		fflush(logfile);
 		ret_val = system(command);
 		if (ret_val!=0) errx(1,"The command \"%s\" failed with return value %d",command,ret_val);
 		printf("CTMSV %s %ld ", de->d_name, release1);
@@ -723,10 +723,10 @@
 			flag_bogus = 1;
 			break;
 		case 'l':
-			logf = fopen(optarg, "w");
-			if (!logf)
+			logfile = fopen(optarg, "w");
+			if (!logfile)
 				err(1, "%s", optarg);
-			setlinebuf(logf);
+			setlinebuf(logfile);
 			break;
 		case 'q':
 			verbose--;
@@ -742,8 +742,8 @@
 	argc -= optind;
 	argv += optind;
 
-	if (!logf)
-		logf = fopen(_PATH_DEVNULL, "w");
+	if (!logfile)
+		logfile = fopen(_PATH_DEVNULL, "w");
 
 	setbuf(stdout, 0);
 
@@ -756,7 +756,7 @@
 
 	fprintf(stderr, "CTM_BEGIN 2.0 %s %s %s %s\n",
 		argv[0], argv[1], argv[2], argv[3]);
-	fprintf(logf, "CTM_BEGIN 2.0 %s %s %s %s\n",
+	fprintf(logfile, "CTM_BEGIN 2.0 %s %s %s %s\n",
 		argv[0], argv[1], argv[2], argv[3]);
 	printf("CTM_BEGIN 2.0 %s %s %s %s\n",
 		argv[0], argv[1], argv[2], argv[3]);
@@ -773,7 +773,7 @@
 		errx(4, "no changes");
 	} else {
 		printf("CTM_END ");
-		fprintf(logf, "CTM_END\n");
+		fprintf(logfile, "CTM_END\n");
 		if (strncmp(argv[0],"svn",3) != 0)
 			print_stat(stderr, "END: ");
 	}
