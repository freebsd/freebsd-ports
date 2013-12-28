--- mem.c.orig	1993-03-03 22:11:23.000000000 +0100
+++ mem.c	2013-06-16 23:49:12.000000000 +0200
@@ -1,38 +1,36 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)mem.c	9.6 92/08/25";
+static const char	*sccsid = "@(#)mem.c	9.6 92/08/25";
 #endif
 
 #include "def.h"
 
 /* exports */
 long Ncount;
-extern void freelink(), wasted(), freetable();
-extern long allocation();
 
 /* imports */
-extern char *Netchars;
-extern int Vflag;
-extern void die();
-extern int strlen();
 #ifdef DEBUG
-extern char *sbrk();
+#include <unistd.h>
+#endif
+
+#ifdef MYMALLOC
+STATIC void addtoheap(char *p, long size);
 #endif
 
 /* privates */
-STATIC void nomem();
-static link *Lcache;
-static unsigned int Memwaste;
+STATIC void nomem(void);
+static palink *Lcache;
+static unsigned long Memwaste;
 
-link	*
+palink	*
 newlink()
-{	register link *rval;
+{	register palink *rval;
 
 	if (Lcache) {
 	 	rval = Lcache;
 		Lcache = Lcache->l_next;
-		strclear((char *) rval, sizeof(link));
-	} else if ((rval = (link * ) calloc(1, sizeof(link))) == 0)
+		strclear((char *) rval, sizeof(palink));
+	} else if ((rval = (palink * ) calloc(1, sizeof(palink))) == 0)
 		nomem();
 	return rval;
 }
@@ -40,7 +38,7 @@
 /* caution: this destroys the contents of l_next */
 void
 freelink(l)
-	link *l;
+	palink *l;
 {
 	l->l_next = Lcache;
 	Lcache = l;
@@ -69,7 +67,7 @@
 
 char	*
 strsave(s)
-	char *s;
+	const char *s;
 {	register char *r;
 
 	if ((r = malloc((unsigned) strlen(s) + 1)) == 0)
@@ -105,8 +103,6 @@
 	long size;
 {
 #ifdef MYMALLOC
-	STATIC void addtoheap();
-
 	addtoheap((char *) t, size * sizeof(node *));
 #else
 	free((char *) t);
@@ -163,10 +159,9 @@
 #undef calloc
 
 /* imports */
-extern char *malloc(), *calloc();
 
 /* private */
-STATIC int align();
+STATIC int align(char *n);
 
 /* allocate in MBUFSIZ chunks.  4k works ok (less 16 for malloc quirks). */
 #define MBUFSIZ (4 * 1024 - 16)
