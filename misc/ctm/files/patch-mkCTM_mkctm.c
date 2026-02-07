--- mkCTM/mkctm.c.orig	2018-10-27 15:56:22 UTC
+++ mkCTM/mkctm.c
@@ -181,12 +181,16 @@ Equ(const char *dir1, const char *dir2, const char *na
 			goto finish;
 		}
 #endif
-		p1=mmap(0, s1.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
-		if (p1 == (u_char *)MAP_FAILED) { err(3, "%s", buf1); }
+		if (s1.st_size) {
+			p1=mmap(0, s1.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
+			if (p1 == (u_char *)MAP_FAILED) { err(3, "%s", buf1); }
+		}
 		close(fd1);
 
-		p2=mmap(0, s2.st_size, PROT_READ, MAP_PRIVATE, fd2, 0);
-		if (p2 == (u_char *)MAP_FAILED) { err(3, "%s", buf2); }
+		if (s2.st_size) {
+			p2=mmap(0, s2.st_size, PROT_READ, MAP_PRIVATE, fd2, 0);
+			if (p2 == (u_char *)MAP_FAILED) { err(3, "%s", buf2); }
+		}
 		close(fd2);
 
 		/* If identical, we're done. */
@@ -222,6 +226,9 @@ Equ(const char *dir1, const char *dir2, const char *na
 			int j;
 			FILE *F;
 			
+			if (!s1.st_size || !s2.st_size)
+				goto subst;
+
 			if (s1.st_size && p1[s1.st_size-1] != '\n') {
 				if (verbose > 0) 
 					fprintf(stderr,
@@ -295,8 +302,10 @@ Equ(const char *dir1, const char *dir2, const char *na
 			free(ob);
 		}
 	    finish:
-		munmap(p1, s1.st_size);
-		munmap(p2, s2.st_size);
+		if (s1.st_size)
+			munmap(p1, s1.st_size);
+		if (s2.st_size)
+			munmap(p2, s2.st_size);
 	}
 }
 
@@ -325,15 +334,19 @@ Add(const char *dir1, const char *dir2, const char *na
 		fd1 = open(buf2, O_RDONLY);
 		if (fd1 < 0) { err(3, "%s", buf2); }
 		fstat(fd1, &st);
-		p1=mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
-		if (p1 == (u_char *)MAP_FAILED) { err(3, "%s", buf2); }
+		if (st.st_size) {
+			p1=mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd1, 0);
+			if (p1 == (u_char *)MAP_FAILED) { err(3, "%s", buf2); }
+		}
 		close(fd1);
 		m2 = MD5Data(p1, st.st_size, md5_2);
 		name_stat("CTMFM", dir2, name, de);
 		printf(" %s %u\n", m2, (unsigned)st.st_size);
-		fwrite(p1, 1, st.st_size, stdout);
+		if (st.st_size)
+			fwrite(p1, 1, st.st_size, stdout);
 		putchar('\n');
-		munmap(p1, st.st_size);
+		if (st.st_size)
+			munmap(p1, st.st_size);
 		s_new_files++;
 		s_new_bytes += st.st_size;
 	}
@@ -493,6 +506,172 @@ DoDir(const char *dir1, const char *dir2, const char *
 		free(nl2);
 }
 
+void
+SvnAdd(const char *dir1, const char *dir2, struct dirent *de)
+{
+	char current_file[] = "/db/current";
+	char *buf2 = alloca(strlen(dir2) + strlen(current_file) + strlen(de->d_name) + 4);
+	char *tmpdir = getenv("TMPDIR");
+	if (tmpdir == NULL)
+		tmpdir = strdup(_PATH_TMP);
+	char tmpfilebase[] = "/CTMserver.XXXXXXXXXX";
+	char *tmpfilename = alloca(strlen(tmpdir)+strlen(tmpfilebase)+4);
+	int command_size = strlen(dir2) + strlen(tmpdir)+strlen(tmpfilebase) + strlen(de->d_name) + 128;
+	char *command = alloca(command_size+1);
+	int ret_val;
+
+	strcpy(buf2, dir2); strcat(buf2, "/"); strcat(buf2, de->d_name); strcat(buf2, current_file);
+	strcpy(tmpfilename, tmpdir); strcat(tmpfilename, tmpfilebase);
+	mktemp(tmpfilename);
+
+	snprintf(command,command_size,"tar -C %s -cvf %s %s 2>&%d\n",dir2,tmpfilename,de->d_name,fileno(logf));
+	fflush(logf);
+	ret_val = system(command);
+	if (ret_val!=0) errx(1,"The command \"%s\" failed with return value %d",command,ret_val);
+	printf("CTMTR ");
+	change += 2; /* Make sure change is big enough .*/
+
+	StatFile(tmpfilename);
+	printf("%jd\n", st.st_size);
+	snprintf(command,command_size,"cat %s; rm -f %s\n",tmpfilename,tmpfilename);
+	ret_val = system(command);
+	if (ret_val!=0) errx(1,"The command \"%s\" failed with return value %d",command,ret_val);
+	putchar('\n');
+}
+
+void
+SvnEqu(const char *dir1, const char *dir2, struct dirent *de)
+{
+	char current_file[] = "/db/current";
+	char *buf1 = alloca(strlen(dir1) + strlen(current_file) + strlen(de->d_name) + 4);
+	char *buf2 = alloca(strlen(dir2) + strlen(current_file) + strlen(de->d_name) + 4);
+	char *tmpdir = getenv("TMPDIR");
+	if (tmpdir == NULL)
+		tmpdir = strdup(_PATH_TMP);
+	char tmpfilebase[] = "/CTMserver.XXXXXXXXXX";
+	char *tmpfilename = alloca(strlen(tmpdir)+strlen(tmpfilebase)+4);
+	int command_size = strlen(dir2) + strlen(tmpdir)+strlen(tmpfilebase) + strlen(de->d_name) + 128;
+	char *command = alloca(command_size+1);
+	long int release1, release2;
+	FILE *current1, *current2;
+	int ret_val;
+
+	strcpy(buf1, dir1); strcat(buf1, "/"); strcat(buf1, de->d_name); strcat(buf1, current_file);
+	strcpy(buf2, dir2); strcat(buf2, "/"); strcat(buf2, de->d_name); strcat(buf2, current_file);
+	strcpy(tmpfilename, tmpdir); strcat(tmpfilename, tmpfilebase);
+	mktemp(tmpfilename);
+
+	current1 = fopen(buf1,"r");
+	current2 = fopen(buf2,"r");
+
+	if (current1 != NULL) {
+		fscanf(current1,"%ld",&release1);
+		fclose(current1);
+	} else
+		errx(1,"No db/release in %s",buf1);
+	if (current2 != NULL) {
+		fscanf(current2,"%ld",&release2);
+		fclose(current2);
+	} else
+		errx(1,"No db/release in %s",buf2);
+
+	if (release2 > release1) {
+		snprintf(command,command_size,"svnadmin dump %s/%s -r %ld:%ld --incremental --deltas 2>&%d > %s\n",dir2,de->d_name,release1+1,release2,fileno(logf),tmpfilename);
+		fflush(logf);
+		ret_val = system(command);
+		if (ret_val!=0) errx(1,"The command \"%s\" failed with return value %d",command,ret_val);
+		printf("CTMSV %s %ld ", de->d_name, release1);
+		change += 2; /* Make sure change is big enough .*/
+
+		StatFile(tmpfilename);
+		printf("%jd\n", st.st_size);
+		snprintf(command,command_size,"cat %s; rm -f %s\n",tmpfilename,tmpfilename);
+		ret_val = system(command);
+		if (ret_val!=0) errx(1,"The command \"%s\" failed with return value %d",command,ret_val);
+		putchar('\n');
+	}
+}
+
+void
+DoSvn(const char *dir1, const char *dir2)
+{
+	int i1, i2, n1, n2, i;
+	struct dirent **nl1, **nl2;
+	char *buf1 = alloca(strlen(dir1) + 4);
+	char *buf2 = alloca(strlen(dir2) + 4);
+
+	strcpy(buf1, dir1); strcat(buf1, "/");
+	strcpy(buf2, dir2); strcat(buf2, "/");
+	n1 = scandir(buf1, &nl1, dirselect, alphasort);
+	n2 = scandir(buf2, &nl2, dirselect, alphasort);
+	i1 = i2 = -1;
+	GetNext(&i1, &n1, nl1, dir1, "", &s1_ignored, &s1_bogus, &s1_wrong);
+	GetNext(&i2, &n2, nl2, dir2, "", &s2_ignored, &s2_bogus, &s2_wrong);
+	for (;i1 < n1 || i2 < n2;) {
+
+		if (damage_limit && damage > damage_limit)
+			break;
+
+		/* Get next item from list 1 */
+		if (i1 < n1 && !nl1[i1]) 
+			GetNext(&i1, &n1, nl1, dir1, "", 
+				&s1_ignored, &s1_bogus, &s1_wrong);
+
+		/* Get next item from list 2 */
+		if (i2 < n2 && !nl2[i2]) 
+			GetNext(&i2, &n2, nl2, dir2, "", 
+				&s2_ignored, &s2_bogus, &s2_wrong);
+
+		if (i1 >= n1 && i2 >= n2) {
+			/* Done */
+			break;
+		} else if (i1 >= n1 && i2 < n2) {
+			/* end of list 1, add anything left on list 2 */
+			if (nl2[i2]->d_type == DT_REG) {
+				if (strcmp(nl2[i2]->d_name,".ctm_status")==0)
+					Add(dir1, dir2, "", nl2[i2]);
+				else
+					errx(1,"Improper file found in svn archive");
+			} else
+				SvnAdd(dir1, dir2, nl2[i2]);
+			free(nl2[i2]); nl2[i2] = 0;
+		} else if (i1 < n1 && i2 >= n2) {
+			/* end of list 2, delete anything left on list 1 */
+			Del(dir1, dir2, "", nl1[i1]);
+			free(nl1[i1]); nl1[i1] = 0;
+		} else if (!(i = strcmp(nl1[i1]->d_name, nl2[i2]->d_name))) {
+			/* Identical names */
+			if (nl2[i1]->d_type == DT_REG && nl2[i2]->d_type == DT_REG && strcmp(nl2[i2]->d_name,".ctm_status")==0)
+				Equ(dir1, dir2, "", nl1[i1]);
+			else if (nl2[i1]->d_type == DT_DIR && nl2[i2]->d_type == DT_DIR)
+				SvnEqu(dir1, dir2, nl1[i1]);
+			else
+
+				errx(1,"Improper file found in svn archive");
+			free(nl1[i1]); nl1[i1] = 0;
+			free(nl2[i2]); nl2[i2] = 0;
+		} else if (i < 0) {
+			/* Something extra in list 1, delete it */
+			Del(dir1, dir2, "", nl1[i1]);
+			free(nl1[i1]); nl1[i1] = 0;
+		} else {
+			/* Something extra in list 2, add it */
+			if (nl2[i2]->d_type == DT_REG) {
+				if (strcmp(nl2[i2]->d_name,".ctm_status")==0)
+					Add(dir1, dir2, "", nl2[i2]);
+				else
+					errx(1,"Improper file found in svn archive");
+			} else
+				SvnAdd(dir1, dir2, nl2[i2]);
+			free(nl2[i2]); nl2[i2] = 0;
+		}
+	}
+	if (n1 >= 0)
+		free(nl1);
+	if (n2 >= 0)
+		free(nl2);
+}
+
 int
 main(int argc, char **argv)
 {
@@ -581,17 +760,22 @@ main(int argc, char **argv)
 		argv[0], argv[1], argv[2], argv[3]);
 	printf("CTM_BEGIN 2.0 %s %s %s %s\n",
 		argv[0], argv[1], argv[2], argv[3]);
-	DoDir(argv[4], argv[5], "");
+	if (strncmp(argv[0],"svn",3) == 0)
+		DoSvn(argv[4], argv[5]);
+	else
+		DoDir(argv[4], argv[5], "");
 	if (damage_limit && damage > damage_limit) {
 		print_stat(stderr, "DAMAGE: ");
 		errx(1, "damage of %d would exceed %d files", 
 			damage, damage_limit);
-	} else if (change < 2) {
+/* change <= 2 means no change because of .ctm_status and .svn_revision */
+	} else if (change < 3) {
 		errx(4, "no changes");
 	} else {
 		printf("CTM_END ");
 		fprintf(logf, "CTM_END\n");
-		print_stat(stderr, "END: ");
+		if (strncmp(argv[0],"svn",3) != 0)
+			print_stat(stderr, "END: ");
 	}
 	exit(0);
 }
