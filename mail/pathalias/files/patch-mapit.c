--- mapit.c.orig	1993-03-03 22:10:02.000000000 +0100
+++ mapit.c	2013-06-17 00:08:03.000000000 +0200
@@ -1,6 +1,6 @@
 /* pathalias -- by steve bellovin, as told to peter honeyman */
 #ifndef lint
-static char	*sccsid = "@(#)mapit.c	9.16 92/08/25";
+static const char	*sccsid = "@(#)mapit.c	9.16 92/08/25";
 #endif
 
 #include "def.h"
@@ -17,43 +17,38 @@
 long Nheap;		/* end of heap */
 long NumNcopy, Nlink, NumLcopy;
 
-void mapit();
-
 /* imports */
-extern long Nheap, Hashpart, Tabsize, Tcount;
-extern int Tflag, Vflag;
-extern node **Table, *Home;
-extern char *Linkout, *Graphout;
-
-extern void freelink(), resetnodes(), printit(), dumpgraph();
-extern void showlinks(), die();
-extern long pack(), allocation();
-extern link *newlink(), *addlink();
-extern int maptrace(), tiebreaker();
-extern node *ncopy();
-
 
 /* privates */
 static long	Heaphighwater;
-static link	**Heap;
+static palink	**Heap;
 
-STATIC void insert(), heapup(), heapdown(), heapswap(), backlinks();
-STATIC void setheapbits(), mtracereport(), heapchildren(), otracereport();
-STATIC link *min_node();
-STATIC int dehash(), skiplink(), skipterminalalias();
-STATIC Cost costof();
-STATIC node *mappedcopy();
+STATIC void insert(palink *l);
+STATIC void heapup(palink *l);
+STATIC void heapdown(palink *l);
+STATIC void heapswap(long i, long j);
+STATIC void backlinks(void);
+STATIC void setheapbits(register palink *l);
+STATIC void mtracereport(node *from, palink *l, const char *excuse);
+STATIC void heapchildren(register node *n);
+STATIC void otracereport(node *n);
+STATIC palink *min_node(void);
+STATIC int dehash(register node *n);
+STATIC int skiplink(palink *l, node *parent, register Cost cost, int trace);
+STATIC int skipterminalalias(node *n, node *next);
+STATIC Cost costof(register node *prev, register palink *l);
+STATIC node *mappedcopy(register node *n);
 
 /* transform the graph to a shortest-path tree by marking tree edges */
 void
 mapit()
 {	register node *n;
-	register link *l;
+	register palink *l;
 
 	vprintf(stderr, "*** mapping\ttcount = %ld\n", Tcount);
 	Tflag = Tflag && Vflag;		/* tracing here only if verbose */
 	/* re-use the hash table space for the heap */
-	Heap = (link **) Table;
+	Heap = (palink **) Table;
 	Hashpart = pack(0L, Tabsize - 1);
 
 	/* expunge penalties from -a option and make circular copy lists */
@@ -84,7 +79,7 @@
 			n->n_flag |= MAPPED;
 			heapchildren(n);	/* add children to heap */
 		}
-		vprintf(stderr, "heap hiwat %d\nalloc %ldk, ncopy = %ld, nlink = %ld, lcopy = %ld\n", Heaphighwater, allocation(), NumNcopy, Nlink, NumLcopy);
+		vprintf(stderr, "heap hiwat %ld\nalloc %ldk, ncopy = %ld, nlink = %ld, lcopy = %ld\n", Heaphighwater, allocation(), NumNcopy, Nlink, NumLcopy);
 
 		if (Nheap != 0)		/* sanity check */
 			die("null entry in heap");
@@ -116,7 +111,7 @@
 STATIC void
 heapchildren(n)
 	register node *n;
-{	register link *l;
+{	register palink *l;
 	register node *next;
 	register int mtrace;
 	register Cost cost;
@@ -132,11 +127,12 @@
 		if (l->l_flag & LTERMINAL)
 			l->l_to = next = ncopy(n, l);
 
-		if ((n->n_flag & NTERMINAL) && (l->l_flag & LALIAS))
+		if ((n->n_flag & NTERMINAL) && (l->l_flag & LALIAS)) {
 			if (skipterminalalias(n, next))
 				continue;
 			else
 				l->l_to = next = ncopy(n, l);
+		}
 
 		if (next->n_flag & MAPPED) {
 			if (mtrace)
@@ -208,12 +204,12 @@
  */
 STATIC int
 skiplink(l, parent, cost, trace)
-	link *l;		/* new link to this node */
+	palink *l;		/* new link to this node */
 	node *parent;		/* (potential) new parent of this node */
 	register Cost cost;	/* new cost to this node */
 	int trace;		/* trace this link? */
 {	register node *n;	/* this node */
-	register link *lheap;		/* old link to this node */
+	register palink *lheap;		/* old link to this node */
 
 	n = l->l_to;
 
@@ -263,7 +259,7 @@
 STATIC Cost
 costof(prev, l)
 	register node *prev;
-	register link *l;
+	register palink *l;
 {	register node *next;
 	register Cost cost;
 
@@ -296,6 +292,9 @@
 		 || (NETDIR(l) == LRIGHT && (prev->n_flag & HASLEFT)))
 			cost += INF;			/* mixed syntax */
 	}
+					/* Dirk meyer 10.02.94 */
+	if ( cost < 0 )			/* Overflow, more than 31 bit */
+		cost = INF;		/* Limit, to avoid recursive paths */
 
 	return cost;
 }
@@ -303,7 +302,7 @@
 /* binary heap implementation of priority queue */
 STATIC void
 insert(l)
-	link *l;
+	palink *l;
 {	register node *n;
 
 	n = l->l_to;
@@ -336,7 +335,7 @@
  */
 STATIC void
 heapup(l)
-	link *l;
+	palink *l;
 {	register long cindx, pindx;	/* child, parent indices */
 	register Cost cost;
 	register node *child, *parent;
@@ -366,10 +365,10 @@
 }
 
 /* extract min (== Heap[1]) from heap */
-STATIC link	*
+STATIC palink	*
 min_node()
-{	link *rval, *lastlink;
-	register link **rheap;
+{	palink *rval, *lastlink;
+	register palink **rheap;
 
 	if (Nheap == 0)
 		return 0;
@@ -399,9 +398,9 @@
 
 STATIC void
 heapdown(l)
-	link *l;
+	palink *l;
 {	register long pindx, cindx;
-	register link **rheap = Heap;	/* in register -- heavily used */
+	register palink **rheap = Heap;	/* in register -- heavily used */
 	node *child, *rchild, *parent;
 
 	pindx = l->l_to->n_tloc;
@@ -450,7 +449,7 @@
 STATIC void
 heapswap(i, j)
 	long i, j;
-{	register link *temp, **rheap;
+{	register palink *temp, **rheap;
 
 	rheap = Heap;	/* heavily used -- put in register */
 	temp = rheap[i];
@@ -489,7 +488,7 @@
  */
 STATIC void
 backlinks()
-{	register link *l;
+{	register palink *l;
 	register node *n, *child;
 	node *nomap;
 	long i;
@@ -539,7 +538,7 @@
 		if (Vflag > 1)
 			fprintf(stderr, "backlink: %s <- %s\n", nomap->n_name, child->n_name);
 	}
-	vprintf(stderr, "%d backlinks\n", Nheap);
+	vprintf(stderr, "%ld backlinks\n", Nheap);
 }
 
 /* find a mapped copy of n if it exists */
@@ -562,7 +561,7 @@
  */
 STATIC void
 setheapbits(l)
-	register link *l;
+	register palink *l;
 {	register node *n;
 	register node *parent;
 
@@ -588,8 +587,8 @@
 STATIC void
 mtracereport(from, l, excuse)
 	node *from;
-	link *l;
-	char *excuse;
+	palink *l;
+	const char *excuse;
 {	node *to = l->l_to;
 
 	fprintf(stderr, "%-16s ", excuse);
@@ -638,7 +637,7 @@
 #if 00
 	/* this hasn't been used for years */
 	for (i = 1; i < Nheap; i++) {
-		link *l;
+		palink *l;
 
 		vprintf(stderr, "%5d %-16s", i, Heap[i]->l_to->n_name);
 		if ((l = Heap[i]->l_to->n_link) != 0) do {
@@ -647,7 +646,7 @@
 		vprintf(stderr, "\n");
 	}
 	for (i = Hashpart; i < Tabsize; i++) {
-		link *l;
+		palink *l;
 		node *n;
 
 		vprintf(stderr, "%5d %-16s", i, Table[i]->n_name);
