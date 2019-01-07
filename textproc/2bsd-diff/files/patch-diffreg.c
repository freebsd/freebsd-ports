--- diffreg.c.orig	1994-01-11 05:39:33 UTC
+++ diffreg.c
@@ -84,6 +84,25 @@ struct line {
 	int	serial;
 	int	value;
 } *file[2], line;
+
+/* declarations */
+void equiv(struct line *, int, struct line *, int, int *);
+int asciifile(FILE *);
+void prepare(int, FILE *);
+void sort(struct line *, int);
+void unsort(struct line *, int, int *);
+void unravel(int);
+void check();
+void output();
+int stone(int *, int, int *, register int *);
+int readhash(FILE *);
+int newcand(int, int, int);
+int search(int *, int, int);
+void change(int, int, int, int);
+void dump_context_vec();
+void range(int, int, char *);
+void fetch(long *, int, int, FILE *, char *, int);
+
 int	len[2];
 struct	line *sfile[2];	/* shortened by pruning common prefix and suffix */
 int	slen[2];
@@ -140,7 +159,7 @@ char	cup2low[256] = {
 0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff
 };
 
-diffreg()
+void diffreg()
 {
 	register int i, j;
 	FILE *f1, *f2;
@@ -270,12 +289,12 @@ copytemp()
 	char buf[BUFSIZ];
 	register int i, f;
 
-	signal(SIGHUP,done);
-	signal(SIGINT,done);
-	signal(SIGPIPE,done);
-	signal(SIGTERM,done);
-	tempfile = mktemp("/tmp/dXXXXX");
-	f = creat(tempfile,0600);
+	signal(SIGHUP, (sig_t) done);
+	signal(SIGINT, (sig_t) done);
+	signal(SIGPIPE, (sig_t) done);
+	signal(SIGTERM, (sig_t) done);
+	strcpy(tempfile, "/tmp/dXXXXX");
+	f = mkstemp(tempfile);
 	if (f < 0) {
 		fprintf(stderr, "diff: ");
 		perror(tempfile);
@@ -311,16 +330,16 @@ splice(dir, file)
 	return (savestr(buf));
 }
 
-prepare(i, fd)
+void prepare(i, fd)
 	int i;
 	FILE *fd;
 {
 	register struct line *p;
-	register j,h;
+	register int j,h;
 
 	fseek(fd, (long)0, 0);
 	p = (struct line *)talloc(3*sizeof(line));
-	for(j=0; h=readhash(fd);) {
+	for(j=0; (h=readhash(fd));) {
 		p = (struct line *)ralloc((char *)p,(++j+3)*sizeof(line));
 		p[j].value = h;
 	}
@@ -328,9 +347,9 @@ prepare(i, fd)
 	file[i] = p;
 }
 
-prune()
+void prune()
 {
-	register i,j;
+	register int i,j;
 	for(pref=0;pref<len[0]&&pref<len[1]&&
 		file[0][pref+1].value==file[1][pref+1].value;
 		pref++ ) ;
@@ -345,7 +364,7 @@ prune()
 	}
 }
 
-equiv(a,n,b,m,c)
+void equiv(a,n,b,m,c)
 struct line *a, *b;
 int *c;
 {
@@ -373,7 +392,7 @@ int *c;
 	c[j] = -1;
 }
 
-stone(a,n,b,c)
+int stone(a,n,b,c)
 int *a;
 int *b;
 register int *c;
@@ -414,7 +433,7 @@ register int *c;
 	return(k);
 }
 
-newcand(x,y,pred)
+int newcand(x,y,pred)
 {
 	register struct cand *q;
 	clist = (struct cand *)ralloc((char *)clist,++clen*sizeof(cand));
@@ -425,7 +444,7 @@ newcand(x,y,pred)
 	return(clen-1);
 }
 
-search(c, k, y)
+int search(c, k, y)
 int *c;
 {
 	register int i, j, l;
@@ -449,7 +468,7 @@ int *c;
 	return(l+1);
 }
 
-unravel(p)
+void unravel(p)
 {
 	register int i;
 	register struct cand *q;
@@ -466,7 +485,7 @@ unravel(p)
 to confounding by hashing (which result in "jackpot")
 2.  collect random access indexes to the two files */
 
-check()
+void check()
 {
 	register int i, j;
 	int jackpot;
@@ -565,7 +584,7 @@ check()
 */
 }
 
-sort(a,n)	/*shellsort CACM #201*/
+void sort(a,n)	/*shellsort CACM #201*/
 struct line *a;
 {
 	struct line w;
@@ -586,8 +605,8 @@ struct line *a;
 				if(aim < ai)
 					break;	/*wraparound*/
 				if(aim->value > ai[0].value ||
-				   aim->value == ai[0].value &&
-				   aim->serial > ai[0].serial)
+				  (aim->value == ai[0].value &&
+				   aim->serial > ai[0].serial))
 					break;
 				w.value = ai[0].value;
 				ai[0].value = aim->value;
@@ -600,7 +619,7 @@ struct line *a;
 	}
 }
 
-unsort(f, l, b)
+void unsort(f, l, b)
 struct line *f;
 int *b;
 {
@@ -614,9 +633,9 @@ int *b;
 	free((char *)a);
 }
 
-skipline(f)
+int skipline(f)
 {
-	register i, c;
+	register int i, c;
 
 	for(i=1;(c=getc(input[f]))!='\n';i++)
 		if (c < 0)
@@ -624,7 +643,7 @@ skipline(f)
 	return(i);
 }
 
-output()
+void output()
 {
 	int m;
 	register int i0, i1, j1;
@@ -691,7 +710,7 @@ struct	context_vec	*context_vec_start,
    and this means that there were lines appended (beginning at b).
    If c is greater than d then there are lines missing from the to file.
 */
-change(a,b,c,d)
+void change(a,b,c,d)
 {
 	int ch;
 	int lowa,upb,lowc,upd;
@@ -781,7 +800,7 @@ change(a,b,c,d)
 	}
 }
 
-range(a,b,separator)
+void range(a,b,separator)
 char *separator;
 {
 	printf("%d", a>b?b:a);
@@ -790,7 +809,7 @@ char *separator;
 	}
 }
 
-fetch(f,a,b,lb,s,oldfile)
+void fetch(f,a,b,lb,s,oldfile)
 long *f;
 FILE *lb;
 char *s;
@@ -869,13 +888,13 @@ char *s;
  * arranging line in 7-bit bytes and then
  * summing 1-s complement in 16-bit hunks 
  */
-readhash(f)
+int readhash(f)
 register FILE *f;
 {
 	register long sum;
 	register unsigned shift;
-	register t;
-	register space;
+	register int t;
+	register int space;
 
 	sum = 1;
 	space = 0;
@@ -931,12 +950,12 @@ register FILE *f;
 		}
 	}
 	sum = low(sum) + high(sum);
-	return((short)low(sum) + (short)high(sum));
+	return((int)low(sum) + (int)high(sum));
 }
 
 #include <a.out.h>
 
-asciifile(f)
+int asciifile(f)
 	FILE *f;
 {
 	char buf[BUFSIZ];
@@ -960,7 +979,7 @@ asciifile(f)
 
 
 /* dump accumulated "context" diff changes */
-dump_context_vec()
+void dump_context_vec()
 {
 	register int	a, b, c, d;
 	register char	ch;
@@ -1003,15 +1022,15 @@ dump_context_vec()
 				ch = (a <= b) ? 'd' : 'a';
 
 			if (ch == 'a')
-				fetch(ixold,lowa,b,input[0],"  ");
+				fetch(ixold,lowa,b,input[0],"  ", 0);
 			else {
-				fetch(ixold,lowa,a-1,input[0],"  ");
-				fetch(ixold,a,b,input[0],ch == 'c' ? "! " : "- ");
+				fetch(ixold,lowa,a-1,input[0],"  ", 0);
+				fetch(ixold,a,b,input[0],ch == 'c' ? "! " : "- ", 0);
 			}
 			lowa = b + 1;
 			cvp++;
 		}
-		fetch(ixold, b+1, upb, input[0], "  ");
+		fetch(ixold, b+1, upb, input[0], "  ", 0);
 	}
 
 	/* output changes to the "new" file */
@@ -1037,15 +1056,15 @@ dump_context_vec()
 				ch = (a <= b) ? 'd' : 'a';
 
 			if (ch == 'd')
-				fetch(ixnew,lowc,d,input[1],"  ");
+				fetch(ixnew,lowc,d,input[1],"  ", 0);
 			else {
-				fetch(ixnew,lowc,c-1,input[1],"  ");
-				fetch(ixnew,c,d,input[1],ch == 'c' ? "! " : "+ ");
+				fetch(ixnew,lowc,c-1,input[1],"  ", 0);
+				fetch(ixnew,c,d,input[1],ch == 'c' ? "! " : "+ ", 0);
 			}
 			lowc = d + 1;
 			cvp++;
 		}
-		fetch(ixnew, d+1, upd, input[1], "  ");
+		fetch(ixnew, d+1, upd, input[1], "  ", 0);
 	}
 
 	context_vec_ptr = context_vec_start - 1;
