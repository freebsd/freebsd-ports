--- src/common.c.orig	1998-11-10 04:09:01 UTC
+++ src/common.c
@@ -108,21 +108,6 @@ extern WRITE_RETURN_T xwrite(fd, buf, len)
 }
 
 /*
- * Set program name
- */
-extern void setprogname(argv)
-	char **argv;
-{
-	register char *cp;
-
-	if (!progname) {
-		progname = strdup(argv[0]);
-		if (cp = strrchr(progname, '/'))
-			progname = cp + 1;
-	}
-}
-
-/*
  * Do run-time initialization
  */
 extern int init(argc, argv, envp)
@@ -137,7 +122,8 @@ extern int init(argc, argv, envp)
 	if (!isserver)
 		(void) signal(SIGSEGV, sighandler);
 
-	setprogname(argv);
+	if (progname == NULL)
+		progname = basename(argv[0]);
 
 	/*
 	 * Save a copy of our argc and argv before setargs() overwrites them
@@ -393,14 +379,14 @@ extern int sendcmd(cmd, fmt, a1, a2, a3, a4, a5, a6, a
  */
 static u_char rembuf[BUFSIZ];
 static u_char *remptr;
-static int remleft;
+static ssize_t remleft;
 
 #define remc() (--remleft < 0 ? remmore() : *remptr++)
 
 /*
  * Back end to remote read()
  */
-static int remread(fd, buf, bufsiz)
+static ssize_t remread(fd, buf, bufsiz)
 	int fd;
 	u_char *buf;
 	int bufsiz;
@@ -494,7 +480,7 @@ extern int remline(buffer, space, doclean)
 /*
  * Non-line-oriented remote read.
  */
-readrem(p, space)
+ssize_t readrem(p, space)
 	char *p;
 	register int space;
 {
@@ -892,7 +878,7 @@ char *xmalloc(amt)
 	extern POINTER *malloc();
 
 	if ((ptr = (char *)malloc(amt)) == NULL)
-		fatalerr("Cannot malloc %d bytes of memory.", amt);
+		fatalerr("Cannot malloc %zu bytes of memory.", amt);
 
 	return(ptr);
 }
@@ -908,7 +894,7 @@ char *xrealloc(baseptr, amt)
 	extern POINTER *realloc();
 
 	if ((new = (char *)realloc(baseptr, amt)) == NULL)
-		fatalerr("Cannot realloc %d bytes of memory.", amt);
+		fatalerr("Cannot realloc %zu bytes of memory.", amt);
 
 	return(new);
 }
@@ -924,7 +910,7 @@ char *xcalloc(num, esize)
 	extern POINTER *calloc();
 
 	if ((ptr = (char *)calloc(num, esize)) == NULL)
-		fatalerr("Cannot calloc %d * %d = %d bytes of memory.",
+		fatalerr("Cannot calloc %zu * %zu = %zu bytes of memory.",
 		      num, esize, num * esize);
 
 	return(ptr);
