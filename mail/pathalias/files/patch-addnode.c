--- addnode.c.orig	1993-03-03 22:10:02.000000000 +0100
+++ addnode.c	2013-06-16 23:54:57.000000000 +0200
@@ -1,6 +1,6 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)addnode.c	9.7 91/05/23";
+static const char	*sccsid = "@(#)addnode.c	9.7 91/05/23";
 #endif
 
 #include "def.h"
@@ -8,27 +8,18 @@
 #define EQ(n, s)	(*(n)->n_name == *(s) && strcmp((n)->n_name, (s)) == 0)
 
 /* exports */
-node *addnode(), *addprivate();
-void alias(), hashanalyze(), fixprivate();
 node **Table;				/* hash table ^ priority queue */
 long Tabsize;				/* size of Table */	
 
 /* imports */
-extern link *addlink();
-extern node *newnode(), **newtable();
-extern char *strsave();
-extern int Iflag, Tflag, Vflag, InetFlag;
-extern node **Table, *Home;
-extern long Ncount, Tabsize;
-extern char **Argv;
-extern void atrace(), die(), freetable();
-extern int strcmp();
 
 /* privates */
-STATIC void crcinit(), rehash(), lowercase();
-STATIC long fold();
-STATIC long hash();
-STATIC node *isprivate();
+STATIC void crcinit(void);
+STATIC void rehash(void);
+STATIC void lowercase(register char *s);
+STATIC long fold(register char *s);
+STATIC long hash(char *name, int unique);
+STATIC node *isprivate(register char *name);
 static node *Private;	/* list of private nodes in current input file */
 /*
  * these numbers are chosen because:
@@ -83,7 +74,7 @@
 alias(n1, n2)
 	node *n1, *n2;
 {
-	link	*l;
+	palink	*l;
 
 	if (ISADOMAIN(n1) && ISADOMAIN(n2)) {
 		fprintf(stderr, "%s: domain alias %s = %s is illegal\n", Argv[0], n1->n_name, n2->n_name);
@@ -219,7 +210,7 @@
 	Tabsize = Primes[++Tabindex];
 	if (Tabsize == 0)
 		die("too many hosts");	/* need more prime numbers */
-	vprintf(stderr, "rehash into %d\n", Tabsize);
+	vprintf(stderr, "rehash into %ld\n", Tabsize);
 	Table = newtable(Tabsize);
 	Tab128 = (HIGHWATER * Tabsize * 128L)/100L;
 
