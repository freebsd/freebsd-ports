--- readnews/readnews.c.orig	1995-04-28 03:12:21.000000000 +0200
+++ readnews/readnews.c	2014-02-07 16:57:21.000000000 +0100
@@ -33,7 +33,7 @@
 
 active *alist;		/* internal active list */
 
-long now;		/* current time */
+time_t now;		/* current time */
 bool interrupt;		/* if interrupt hit */
 char *newsdir;		/* %news */
 bool su;		/* if super user (not used) */
@@ -783,11 +783,12 @@
 	helppath = ctlfile("readnews.help");
 	if ((f = fopen(helppath, "r")) == NIL(FILE)) {
 		(void) printf("Can't open %s\n", helppath);
-		return;
+		return 0;
 	}
 	while ((c = getc(f)) != EOF)
 		(void) putc(c, stdout);
 	(void) fclose(f);
+	return 0;
 }
 
 /*
@@ -806,7 +807,7 @@
 #ifdef UNSWMAIL
 	argv[argc++] = "-s";
 	if ((argv[argc++] = getsubject(hp)) == NIL(char))
-		return;
+		return 0;
 	argv[argc++] = "-i";
 	argv[argc++] = fname;
 #endif
@@ -821,6 +822,7 @@
 	run(mailpath, argv, false);
 
 	free(argv[argc - 2]);
+	return 0;
 }
 
 
@@ -838,7 +840,7 @@
 	char *s = getsubject(hp);
 
 	if (s == NULL)
-		return;
+		return 0;
 	(void) strcpy(tmpf, "/tmp/rfXXXXXX");
 	(void) mktemp(tmpf);
 	fo = fopen(tmpf, "w");
@@ -859,6 +861,7 @@
 	free(s);
 
 	(void) unlink(tmpf);
+	return 0;
 }
 
 /*
@@ -950,20 +953,20 @@
 	register char *cp;
 	register FILE	*sf;
 	register char *aname;
-	long then;
+	time_t then;
 	extern char *getenv();
 
 	if (!*s) {
 		if ((aname = getenv("HOME")) == NIL(char)) {
 			(void) printf("No $HOME in environment.\n");
-			return;
+			return 0;
 		}
 		s = aname = newstr3(aname, "/", ARTICLES);
 	} else
 		aname = NIL(char);
 	if ((sf = fopen(s, "a")) == NIL(FILE)) {
 		(void) fprintf(stderr, "readnews: can't open %s\n", s);
-		return;
+		return 0;
 	}
 	if (aname)
 		free(aname);
@@ -983,6 +986,7 @@
 	(void) putc('\n', sf);
 	(void) fclose(sf);
 	fseek(f, pos, 0);
+	return 0;
 }
 
 /*
@@ -1083,7 +1087,7 @@
 	fname = ctlfile("readnews.ctl");
 	f = fopen(fname, "r");
 	if (f == NULL)
-		return;
+		return 0;
 
 	while (fgets(line, sizeof(line), f) != NULL) {
 		line[strlen(line)-1] = '\0';	/* dispose of newline */
@@ -1103,4 +1107,5 @@
 	}
 
 	(void) fclose(f);
+	return 0;
 }
