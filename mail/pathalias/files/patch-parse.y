--- parse.y.orig	1993-03-03 22:10:03.000000000 +0100
+++ parse.y	2013-06-16 17:16:43.000000000 +0200
@@ -1,10 +1,11 @@
 %{
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)parse.y	9.11 91/06/01";
+static const char	*sccsid = "@(#)parse.y	9.11 91/06/01";
 #endif /* lint */
 
 #include "def.h"
+#include <string.h>
 
 /* scanner states (yylex, parse) */
 #define OTHER		0
@@ -14,14 +15,8 @@
 
 /* exports */
 long Tcount;
-extern void yyerror();
 
 /* imports */
-extern node *addnode(), *addprivate();
-extern void fixprivate(), alias(), deadlink(), deletelink();
-extern link *addlink();
-extern int strcmp();
-extern char *strsave();
 extern int optind;
 extern char *Cfile, *Netchars, **Argv;
 extern int Lineno, Argc;
@@ -78,7 +73,7 @@
 	;
 
 links	: host site cost {
-		struct link *l;
+		struct palink *l;
 
 		l = addlink($1, $2.ys_node, $3, $2.ys_net, $2.ys_dir);
 		if (GATEWAYED($2.ys_node))
@@ -87,7 +82,7 @@
 			l->l_flag |= LTERMINAL;
 	  }			
 	| links ',' site cost {
-		struct link *l;
+		struct palink *l;
 
 		l = addlink($1, $3.ys_node, $4, $3.ys_net, $3.ys_dir);
 		if (GATEWAYED($3.ys_node))
@@ -238,18 +233,18 @@
 %%
 
 void
-#ifdef YYDEBUG
+#if YYDEBUG
 /*VARARGS1*/
 yyerror(fmt, arg)
-	char *fmt, *arg;
+	const char *fmt, *arg;
 #else
 yyerror(s)
-	char *s;
+	const char *s;
 #endif
 {
 	/* a concession to bsd error(1) */
 	fprintf(stderr, "\"%s\", ", Cfile);
-#ifdef YYDEBUG
+#if YYDEBUG
 	fprintf(stderr, "line %d: ", Lineno);
 	fprintf(stderr, fmt, arg);
 	putc('\n', stderr);
@@ -279,7 +274,7 @@
 	Cost cost;
 	char netchar, netdir;
 {	register node *member, *nextnet;
-	link *l;
+	palink *l;
 	static int netanon = 0;
 	char anon[25];
 
@@ -314,7 +309,7 @@
 #define NLRETURN() {Scanstate = NEWLINE; return EOL;}
 
 static struct ctable {
-	char *cname;
+	const char *cname;
 	Cost cval;
 } ctable[] = {
 	/* ordered by frequency of appearance in a "typical" dataset */
@@ -524,7 +519,7 @@
 adjust(n, cost)
 	node *n;
 	Cost cost;
-{	link *l;
+{	palink *l;
 
 	n->n_cost += cost;	/* cumulative */
 
