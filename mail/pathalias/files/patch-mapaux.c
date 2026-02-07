--- mapaux.c.orig	1993-03-03 22:10:03.000000000 +0100
+++ mapaux.c	2013-06-17 00:07:15.000000000 +0200
@@ -1,33 +1,21 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)mapaux.c	9.8 91/06/23";
+static const char	*sccsid = "@(#)mapaux.c	9.8 91/06/23";
 #endif /* lint */
 
 #include "def.h"
 
 /* imports */
-extern long Nheap, Hashpart, Tabsize, NumNcopy, Nlink, NumLcopy;
-extern node **Table, *Home;
-extern char *Graphout, *Linkout, *Netchars, **Argv;
-extern int Vflag;
-extern void freelink(), die();
-extern long pack();
-extern link *newlink();
-extern node *newnode();
-extern char *strsave();
-extern int strcmp(), strlen();
 
 /* exports */
-extern long pack();
-extern void resetnodes(), dumpgraph(), showlinks(), terminalnet();
-extern int tiebreaker();
-extern node *ncopy();
 
 /* privates */
 static FILE *Gstream;	/* for dumping graph */
-STATIC void dumpnode(), untangle(), dfs();
-STATIC int height();
-STATIC link *lcopy();
+STATIC void dumpnode(register node *from);
+STATIC void untangle(void);
+STATIC void dfs(register node *n);
+STATIC int height(register node *n);
+STATIC palink *lcopy(register node *parent, register node *n);
 
 /*
  * slide everything from Table[low] to Table[high]
@@ -103,8 +91,8 @@
 dumpnode(from)
 	register node *from;
 {	register node *to;
-	register link *l;
-	link *lnet = 0, *ll, *lnext;
+	register palink *l;
+	palink *lnet = 0, *ll, *lnext;
 
 	for (l = from->n_link ; l; l = l->l_next) {
 		to = l->l_to;
@@ -182,7 +170,7 @@
 STATIC void
 dfs(n)
 	register node *n;
-{	register link *l;
+{	register palink *l;
 	register node *next;
 
 	n->n_flag |= INDFS;
@@ -203,7 +191,7 @@
 
 void
 showlinks() 
-{	register link *l;
+{	register palink *l;
 	register node *n;
 	register long i;
 	FILE	*estream;
@@ -223,7 +211,7 @@
 			fputs(l->l_to->n_name, estream);
 			if (NETDIR(l) == LLEFT)
 				putc(NETCHAR(l), estream);
-			fprintf(estream, "(%d)\n", l->l_cost);
+			fprintf(estream, "(%ld)\n", l->l_cost);
 		}
 	}
 	(void) fclose(estream);
@@ -323,7 +311,7 @@
 node *
 ncopy(parent, l)
 	register node *parent;
-	register link *l;
+	register palink *l;
 {	register node *n, *ncp;
 
 #ifdef DEBUG
@@ -359,11 +347,11 @@
  *
  * why copy any links other than aliases?  hmmm ...
  */
-STATIC link *
+STATIC palink *
 lcopy(parent, n)
 	register node *parent, *n;
-{	register link *l, *lcp;
-	link *first = 0, *last = 0;
+{	register palink *l, *lcp;
+	palink *first = 0, *last = 0;
  
 	for (l = n->n_link; l != 0; l = l->l_next) {
 		/* skip if dest is already mapped */
