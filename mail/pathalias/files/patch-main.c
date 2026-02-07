--- main.c.orig	1993-03-03 22:10:02.000000000 +0100
+++ main.c	2013-06-16 23:52:03.000000000 +0200
@@ -1,6 +1,6 @@
-/* pathalias -- by steve bellovin, as told to peter honeyman */
+/*_pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)main.c	9.8 91/06/11";
+static const char	*sccsid = "@(#)main.c	9.8 91/06/11";
 #endif
 
 #ifndef VMS
@@ -9,10 +9,11 @@
 #define	MAIN	XXmain
 #endif
 
+#include <unistd.h>
 #include "def.h"
 
 /* exports */
-char *Cfile;	/* current input file */
+const char *Cfile;	/* current input file */
 char *Graphout;	/* file for dumping edges (-g option) */
 char *Linkout;	/* file for dumping shortest path tree */
 char **Argv;	/* external copy of argv (for input files) */
@@ -26,26 +27,17 @@
 int InetFlag;	/* local host is w/in scope of DNS (-I flag) */
 int Lineno = 1;	/* line number within current input file */
 int Argc;	/* external copy of argc (for input files) */
-extern void die();
-extern int tracelink();
 
 /* imports */
-extern char *optarg;
-extern int optind;
-extern long Lcount, Ncount;
-extern long allocation();
-extern void wasted(), mapit(), hashanalyze(), deadlink();
-extern char *local();
-extern node *addnode();
-extern int getopt(), yyparse();
-extern void printit();
 
 #define USAGE "usage: %s [-vciDfI] [-l localname] [-d deadlink] [-t tracelink] [-g edgeout] [-s treeout] [-a avoid] [files ...]\n"
 
+int
 MAIN(argc, argv) 
 	register int argc; 
 	register char **argv;
-{	char *locname = 0, *bang;
+{	const char *locname = 0;
+	char *bang;
 	register int c;
 	int errflg = 0;
 
@@ -122,14 +114,14 @@
 				Argv[0], locname);
 	}
 
-	Home = addnode(locname);	/* add home node */
+	Home = addnode(strsave(locname));	/* add home node */
 	Home->n_cost = 0;		/* doesn't cost to get here */
 
 	(void) yyparse();			/* read in link info */
 
 	if (Vflag > 1)
 		hashanalyze();
-	vprintf(stderr, "%d nodes, %d links, alloc %ldk\n", 
+	vprintf(stderr, "%ld nodes, %ld links, alloc %ldk\n", 
 				Ncount, Lcount, allocation());
 
 	Cfile = "[backlinks]";	/* for tracing back links */
@@ -150,7 +142,7 @@
 
 void
 die(s)
-	char *s;
+	const char *s;
 {
 #ifdef DEBUG
 	extern int abort();
