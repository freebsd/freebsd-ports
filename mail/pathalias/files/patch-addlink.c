--- addlink.c.orig	1993-03-03 22:10:01.000000000 +0100
+++ addlink.c	2013-06-16 23:45:51.000000000 +0200
@@ -1,39 +1,32 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)addlink.c	9.7 88/06/10";
+static const char	*sccsid = "@(#)addlink.c	9.7 88/06/10";
 #endif /* lint */
 
 #include "def.h"
 
 /* exports */
-extern link *addlink();
-extern void deadlink(), atrace(), freelink();
-extern int tracelink(), maptrace();
-char *Netchars = "!:@%";	/* sparse, but sufficient */
 long Lcount;			/* how many edges? */
 
 /* imports */
-extern int Tflag, Dflag;
-extern link *newlink();
-extern node *addnode();
-extern void yyerror(), die();
-extern int strcmp(), strlen();
 
 /* privates */
-STATIC void netbits(), ltrace(), ltrprint();
-static link	*Trace[NTRACE];
+STATIC void netbits(register palink *l, int netchar,int netdir);
+STATIC void ltrace(node *from, node *to, Cost cost, int netchar, int netdir, const char *message);
+STATIC void ltrprint(node *from, node *to, Cost cost, int netchar, int netdir, const char *message);
+static palink	*Trace[NTRACE];
 static int	Tracecount;
 
 #define EQ(n1, n2)	(strcmp((n1)->n_name, (n2)->n_name) == 0)
 #define LTRACE		if (Tflag) ltrace
 
-link *
+palink *
 addlink(from, to, cost, netchar, netdir)
 	node *from;
 	register node *to;
 	Cost cost;
 	char netchar, netdir;
-{	register link *l, *prev = 0;
+{	register palink *l, *prev = 0;
 
 	LTRACE(from, to, cost, netchar, netdir, "");
 	/*
@@ -89,7 +82,7 @@
 void
 deadlink(nleft, nright) 
 	node *nleft, *nright;
-{	link *l, *lhold = 0, *lprev, *lnext;
+{	palink *l, *lhold = 0, *lprev, *lnext;
 
 	/* DEAD host */
 	if (nright == 0) {
@@ -132,7 +125,7 @@
 
 STATIC void
 netbits(l, netchar, netdir)
-	register link *l;
+	register palink *l;
 	char netchar, netdir;
 {
 	l->l_flag &= ~LDIR;
@@ -144,7 +137,7 @@
 tracelink(arg) 
 	char *arg;
 {	char *bang;
-	link *l;
+	palink *l;
 
 	if (Tracecount >= NTRACE)
 		return -1;
@@ -170,8 +163,9 @@
 ltrace(from, to, cost, netchar, netdir, message)
 	node *from, *to;
 	Cost cost;
-	char netchar, netdir, *message;
-{	link *l;
+	char netchar, netdir;
+	const char *message;
+{	palink *l;
 	int i;
 
 	for (i = 0; i < Tracecount; i++) {
@@ -194,7 +188,8 @@
 ltrprint(from, to, cost, netchar, netdir, message)
 	node *from, *to;
 	Cost cost;
-	char netchar, netdir, *message;
+	char netchar, netdir;
+	const char *message;
 {	char buf[256], *bptr = buf;
 
 	strcpy(bptr, from->n_name);
@@ -213,7 +208,7 @@
 void
 atrace(n1, n2)
 	node *n1, *n2;
-{	link *l;
+{	palink *l;
 	int i;
 	char buf[256];
 
@@ -230,7 +225,7 @@
 int
 maptrace(from, to)
 	register node *from, *to;
-{	register link *l;
+{	register palink *l;
 	register int i;
 
 	for (i = 0; i < Tracecount; i++) {
@@ -248,7 +243,7 @@
 deletelink(from, to)
 	node *from;
 	node *to;
-{	register link *l, *lnext;
+{	register palink *l, *lnext;
 
 	l = from->n_link;
 
