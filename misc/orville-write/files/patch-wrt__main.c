--- wrt_main.c.orig	2004-09-29 04:43:17 UTC
+++ wrt_main.c
@@ -38,7 +38,7 @@ char myname[UT_NAMESIZE+1]= "";	/* my name (based on u
 char myuidname[UT_NAMESIZE+1];	/* my name (based on uid number) */
 char *mytty;			/* my tty name in "tty##" format */
 #ifdef TTYPERMS
-int myperms;			/* my original tty perms */
+extern int myperms;		/* my original tty perms */
 #endif /*TTYPERMS*/
 
 FILE *histerm;		/* Opened version of device to write to */
