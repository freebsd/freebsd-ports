--- ./sls.c.orig	2013-10-11 17:05:37.000000000 -0300
+++ ./sls.c	2013-10-11 17:06:06.000000000 -0300
@@ -24,7 +24,10 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <errno.h>
+#include <dirent.h>
 
 #define ISEXEC(m)	(m & (S_IEXEC|(S_IEXEC>>3)|(S_IEXEC>>6)))
 #define MAXUIDS		200	/* max #of user names from passwd file */
@@ -86,12 +89,14 @@
 static int    sortsfile(), sortfile();
 static time_t getsixmosago();		/* for emulating 'ls' date silliness */
 
-extern char  *getenv(), *malloc(), *realloc();
-extern int    errno;
-extern time_t time();
-
+void dirread (char *dirname);
+void dofile (register char *fname, int cmdarg);
+void selectfs (register char *fname, register struct stat *psbuf);
+void selectf (register char *fname);
+void display (SFILESTAT *pf);
 /******************************************************************************/
 
+int
 main (ac, av)
     int            ac;
     char          *av[];
@@ -211,6 +216,7 @@
 
 /******************************************************************************/
 
+void
 dofile (fname, cmdarg)
     register char  *fname;	/* name of file to stat and list */
     int             cmdarg;	/* =1 if fname was command line arg */
@@ -267,11 +273,12 @@
 
 /******************************************************************************/
 
+void
 dirread (dirname)
     char           *dirname;
 {  /* read a directory and everything under it that's on the same device */
     register DIR   *dirp;		/* ptr to directory list */
-    register struct direct  *dentp;	/* ptr to directory entry */
+    register struct dirent  *dentp;	/* ptr to directory entry */
     register char  *pfname;
     register int    len;
     char            fname[512];		/* maximum pathname length */
@@ -314,6 +321,7 @@
 
 /******************************************************************************/
 
+void
 selectf (fname)
     register char *fname;
 {  /* allocate space for this file name for sorting */
@@ -356,6 +364,7 @@
 
 /******************************************************************************/
 
+void
 selectfs (fname, psbuf)
     register char *fname;
     register struct stat  *psbuf;
@@ -594,6 +603,7 @@
 
 /******************************************************************************/
 
+void
 display (pf)
     SFILESTAT       *pf;
 {  /* display info about a file */
