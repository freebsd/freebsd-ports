--- def.h.orig	1993-03-03 22:10:01.000000000 +0100
+++ def.h	2013-06-17 00:07:48.000000000 +0200
@@ -2,7 +2,7 @@
 
 #ifndef lint
 #ifdef MAIN
-static char	*h_sccsid = "@(#)def.h	9.8 91/06/11";
+static const char	*h_sccsid = "@(#)def.h	9.8 91/06/11";
 #endif /*MAIN*/
 #endif /*lint*/
 
@@ -13,7 +13,7 @@
 
 typedef	long Cost;
 typedef struct node node;
-typedef struct link link;
+typedef struct palink palink;
 typedef struct dom dom;
 
 #ifdef lint
@@ -63,7 +63,7 @@
 /* WARNING: if > 2^16 nodes, type of n_tloc must change */
 struct node {
 	char	*n_name;	/* host name */
-	link	*n_link;	/* adjacency list */
+	palink	*n_link;	/* adjacency list */
 	Cost	n_cost;		/* cost to this host */
 	union {
 		node *nu_net;	/* others in this network (parsing) */
@@ -114,11 +114,11 @@
 #define l_next un.lu_next
 #define l_from un.lu_from
 
-struct link {
+struct palink {
 	node	*l_to;		/* adjacent node */
 	Cost	l_cost;		/* edge cost */
 	union {
-		link *lu_next;	/* rest of adjacency list (not tracing) */
+		palink *lu_next;	/* rest of adjacency list (not tracing) */
 		node *lu_from;	/* source node (tracing) */
 	} un;
 	short	l_flag;		/* right/left syntax, flags */
@@ -133,7 +133,7 @@
  */
 struct node {
 	char	*n_name;
-	link	*n_link;
+	palink	*n_link;
 	Cost	n_cost;
 	node	*n_net;
 	node	*n_root;
@@ -143,10 +143,10 @@
 	unsigned short n_tloc;
 	unsigned short n_flag;
 };
-struct link {
+struct palink {
 	node	*l_to;
 	Cost	l_cost;
-	link	*l_next;
+	palink	*l_next;
 	node	*l_from;
 	short	l_flag;
 	char	l_netop;
@@ -159,3 +159,85 @@
 	dom *prev;
 	char *name;
 };
+
+/* prototypes addlink.c */
+extern palink *addlink(node *from, register node *to, Cost cost, int netchar, int netdir);
+extern void deadlink(node *nleft, node *nright);
+extern void atrace(node *n1, node *n2);
+extern int tracelink(char *arg);
+extern void deletelink(node *from, node *to);
+extern int maptrace(register node *from, register node *to);
+extern long Lcount;
+
+/* prototypes addnode.c */
+extern node *addnode(register char *name);
+extern node *addprivate(register char *name);
+extern void alias(node *n1, node *n2);
+extern void hashanalyze(void);
+extern void fixprivate(void);
+extern node *addhidden(register char *name);
+extern node **Table;
+extern long Tabsize;
+
+/* prototypes domain.c */
+extern int ondomlist(dom **headp, char *domain);
+extern int nslookup(char *domain);
+extern void adddom(dom **headp, char *domain);
+extern void movetofront(dom **headp, dom *d);
+extern int isadomain(char *domain);
+
+/* prototypes local.c */
+extern char *local(void);
+
+/* prototypes main.c */
+extern void die(const char *s);
+extern const char *Cfile;
+extern char *Graphout;
+extern char *Linkout;
+extern char **Argv;
+extern node *Home;
+extern int Cflag;
+extern int Dflag;
+extern int Iflag;
+extern int Tflag;
+extern int Vflag;
+extern int Fflag;
+extern int InetFlag;
+extern int Lineno;
+extern int Argc;
+
+/* prototypes mapaux.c */
+extern long pack(long low, long high);
+extern void resetnodes(void);
+extern void dumpgraph(void);
+extern void showlinks(void);
+extern int tiebreaker(node *n, register node *newp );
+extern node *ncopy(register node *parent, register palink *l);
+
+/* prototypes mapit.c */
+void mapit(void);
+extern long Nheap, Hashpart, NumNcopy, Nlink, NumLcopy;
+
+/* prototypes mem.c */
+extern void freelink(palink *l);
+extern void wasted(void);
+extern void freetable(node **t, long size);
+extern long allocation(void);
+extern palink *newlink(void);
+extern node *newnode(void);
+extern dom *newdom(void);
+extern char *strsave(const char *s);
+extern node **newtable(long size);
+#ifdef MYMALLOC
+extern char *mymalloc(register unsigned int n);
+#endif
+extern long Ncount;
+
+/* prototypes parse.c */
+extern void yyerror(const char *s);
+extern int yyparse(void);
+extern long Tcount;
+
+/* prototypes printit.c */
+extern void printit(void);
+
