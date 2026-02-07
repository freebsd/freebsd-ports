--- printit.c.orig	1993-03-03 22:10:03.000000000 +0100
+++ printit.c	2013-06-17 00:12:38.000000000 +0200
@@ -1,6 +1,6 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)printit.c	9.4 89/02/07";
+static const char	*sccsid = "@(#)printit.c	9.4 89/02/07";
 #endif
 
 #include "def.h"
@@ -11,27 +11,27 @@
  */
 
 /* exports */
-extern void printit();
 
 /* imports */
-extern int Cflag, Vflag, Dflag, Fflag;
-extern node *Home;
-extern char *Netchars;
-extern void die();
-extern int strlen();
 
 /* privates */
-static link *Ancestor;	/* for -f option */
-STATIC void preorder(), setpath(), printhost(), printdomain();
-STATIC char *hostpath();
-STATIC int printable();
+static palink *Ancestor;	/* for -f option */
+STATIC void preorder(register palink *l, char *ppath);
+STATIC void setpath(palink *l, register char *ppath, register char *npath);
+STATIC void printhost(register node *n, char *path, Cost cost);
+STATIC void printdomain(register node *n, char *path, Cost cost);
+STATIC char *hostpath(register char *path, register palink *l, int netchar);
+STATIC int printable(register node *n);
 
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
@@ -57,7 +57,7 @@
  */
 STATIC void
 preorder(l, ppath)
-	register link *l;
+	register palink *l;
 	char *ppath;
 {	register node *n;
 	node *ncp;		/* circular copy list */
@@ -105,7 +105,7 @@
 printable(n)
 	register node *n;
 {	node *ncp;
-	link *l;
+	palink *l;
 
 	if (n->n_flag & PRINTED)
 		return 0;
@@ -156,7 +156,7 @@
 
 STATIC void
 setpath(l, ppath, npath) 
-	link *l;
+	palink *l;
 	register char *ppath, *npath;
 {	register node *next, *parent;
 	char netchar;
@@ -192,11 +192,12 @@
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
@@ -224,7 +225,7 @@
 STATIC char *
 hostpath(path, l, netchar)
 	register char *path;
-	register link *l;
+	register palink *l;
 	char netchar;
 {	register node *prev;
 
