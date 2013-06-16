--- printit.c.orig	1993-03-03 22:10:03.000000000 +0100
+++ printit.c	2013-06-16 17:17:32.000000000 +0200
@@ -1,9 +1,10 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)printit.c	9.4 89/02/07";
+static const char	*sccsid = "@(#)printit.c	9.4 89/02/07";
 #endif
 
 #include "def.h"
+#include <string.h>
 
 /*
  * print the routes by traversing the shortest path tree in preorder.
@@ -11,27 +12,28 @@
  */
 
 /* exports */
-extern void printit();
+extern void printit(void);
 
 /* imports */
 extern int Cflag, Vflag, Dflag, Fflag;
 extern node *Home;
 extern char *Netchars;
-extern void die();
-extern int strlen();
 
 /* privates */
-static link *Ancestor;	/* for -f option */
+static palink *Ancestor;	/* for -f option */
 STATIC void preorder(), setpath(), printhost(), printdomain();
 STATIC char *hostpath();
 STATIC int printable();
 
 /* in practice, even the longest paths are < 100 bytes */
-#define PATHSIZE 512
+/* Dirk meyer 10.02.94 */
+/* in reality we have reached paths up to 200 bytes */
+/* the path must fit two times in the buffer */
+#define PATHSIZE 4096
 
 void
 printit()
-{	link *l;
+{	palink *l;
 	char pbuf[PATHSIZE];
 
 	/* print home */
@@ -57,7 +59,7 @@
  */
 STATIC void
 preorder(l, ppath)
-	register link *l;
+	register palink *l;
 	char *ppath;
 {	register node *n;
 	node *ncp;		/* circular copy list */
@@ -105,7 +107,7 @@
 printable(n)
 	register node *n;
 {	node *ncp;
-	link *l;
+	palink *l;
 
 	if (n->n_flag & PRINTED)
 		return 0;
@@ -156,7 +158,7 @@
 
 STATIC void
 setpath(l, ppath, npath) 
-	link *l;
+	palink *l;
 	register char *ppath, *npath;
 {	register node *next, *parent;
 	char netchar;
@@ -192,11 +194,12 @@
 		return;
 	}
 		
-	if (netchar == '@')
+	if (netchar == '@') {
 		if (next->n_flag & ATSIGN)
 			netchar = '%';	/* shazam?  shaman? */
 		else
 			next->n_flag |= ATSIGN;
+	}
 
 	/* remainder should be a sprintf -- foo on '%' as an operator */
 	for ( ; (*npath = *ppath) != 0; ppath++) {
@@ -224,7 +227,7 @@
 STATIC char *
 hostpath(path, l, netchar)
 	register char *path;
-	register link *l;
+	register palink *l;
 	char netchar;
 {	register node *prev;
 
