--- parse.y.orig	1993-03-03 22:10:03.000000000 +0100
+++ parse.y	2013-06-17 00:03:43.000000000 +0200
@@ -1,9 +1,10 @@
 %{
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)parse.y	9.11 91/06/01";
+static const char	*sccsid = "@(#)parse.y	9.11 91/06/01";
 #endif /* lint */
 
+#include <unistd.h>
 #include "def.h"
 
 /* scanner states (yylex, parse) */
@@ -14,22 +15,16 @@
 
 /* exports */
 long Tcount;
-extern void yyerror();
 
 /* imports */
-extern node *addnode(), *addprivate();
-extern void fixprivate(), alias(), deadlink(), deletelink();
-extern link *addlink();
-extern int strcmp();
-extern char *strsave();
-extern int optind;
-extern char *Cfile, *Netchars, **Argv;
-extern int Lineno, Argc;
-extern node *Home;
 
 /* privates */
-STATIC void fixnet(), adjust();
-STATIC int yylex(), yywrap(), getword();
+STATIC void fixnet(register node *network, node *nlist, Cost cost, int netchar, int netdir);
+STATIC void adjust(node *n, Cost cost);
+STATIC int yylex(void);
+STATIC int yywrap(void);
+STATIC int getword(register char *str, register int c);
+static const char *Netchars = "!:@%";	/* sparse, but sufficient */
 static int Scanstate = NEWLINE;	/* scanner (yylex) state */
 
 /* flags for ys_flags */
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
@@ -99,11 +94,11 @@
 	;
 
 host	: HOST		{$$ = addnode($1);}
-	| PRIVATE	{$$ = addnode("private");}
-	| DEAD		{$$ = addnode("dead");}
-	| DELETE	{$$ = addnode("delete");}
-	| FILETOK	{$$ = addnode("file");}
-	| ADJUST	{$$ = addnode("adjust");}
+	| PRIVATE	{$$ = addnode(strsave("private"));}
+	| DEAD		{$$ = addnode(strsave("dead"));}
+	| DELETE	{$$ = addnode(strsave("delete"));}
+	| FILETOK	{$$ = addnode(strsave("file"));}
+	| ADJUST	{$$ = addnode(strsave("adjust"));}
 	;
 
 site	: asite {
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
 
