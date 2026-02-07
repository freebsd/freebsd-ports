--- diffh.c.orig	1991-11-12 20:31:33 UTC
+++ diffh.c
@@ -6,6 +6,7 @@ static	char sccsid[] = "@(#)diffh.c 4.4 11/27/85";
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <stdlib.h>
 
 #define C 3
 #define RANGE 30
@@ -20,13 +21,24 @@ int bflag;
 int debug = 0;
 FILE *file[2];
 
+/* declarations */
+void error(char *, char *);
+char cmp(char *, char *);
+void range(long, int);
+void change(long, int, long, int, char *);
+int output(int, int);
+void progerr(char *);
+int hardsynch();
+int easysynch();
+void movstr(char *, char *t);
+void clrl(int, long);
+
 	/* return pointer to line n of file f*/
 char *getl(f,n)
 long n;
 {
 	register char *t;
-	char *malloc();
-	register delta, nt;
+	register int delta, nt;
 again:
 	delta = n - lineno[f];
 	nt = ntext[f];
@@ -43,11 +55,12 @@ again:
 	t = text[f][nt];
 	if(t==0) {
 		t = text[f][nt] = malloc(LEN+1);
-		if(t==NULL)
+		if(t==NULL) {
 			if(hardsynch())
 				goto again;
 			else
 				progerr("5");
+		}
 	}
 	t = fgets(t,LEN,file[f]);
 	if(t!=NULL)
@@ -56,10 +69,10 @@ again:
 }
 
 	/*remove thru line n of file f from storage*/
-clrl(f,n)
+void clrl(f,n)
 long n;
 {
-	register i,j;
+	register int i,j;
 	j = n-lineno[f]+1;
 	for(i=0;i+j<ntext[f];i++)
 		movstr(text[f][i+j],text[f][i]);
@@ -67,14 +80,14 @@ long n;
 	ntext[f] -= j;
 }
 
-movstr(s,t)
+void movstr(s,t)
 register char *s, *t;
 {
-	while(*t++= *s++)
+	while((*t++= *s++))
 		continue;
 }
 
-main(argc,argv)
+int main(argc,argv)
 char **argv;
 {
 	char *s0,*s1;
@@ -116,10 +129,10 @@ char **argv;
 }
 
 	/* synch on C successive matches*/
-easysynch()
+int easysynch()
 {
 	int i,j;
-	register k,m;
+	register int k,m;
 	char *s0,*s1;
 	for(i=j=1;i<RANGE&&j<RANGE;i++,j++) {
 		s0 = getl(0,n0+i);
@@ -148,9 +161,9 @@ cont2:			;
 	return(0);
 }
 
-output(a,b)
+int output(a,b)
 {
-	register i;
+	register int i;
 	char *s;
 	if(a<0)
 		change(n0-1,0,n1,b,"a");
@@ -179,7 +192,7 @@ output(a,b)
 	return(1);
 }
 
-change(a,b,c,d,s)
+void change(a,b,c,d,s)
 long a,c;
 char *s;
 {
@@ -189,7 +202,7 @@ char *s;
 	printf("\n");
 }
 
-range(a,b)
+void range(a,b)
 long a;
 {
 	if(b==INF)
@@ -200,7 +213,7 @@ long a;
 		printf("%ld,%ld",a,a+b);
 }
 
-cmp(s,t)
+char cmp(s,t)
 char *s,*t;
 {
 	if(debug)
@@ -224,20 +237,21 @@ char *f1,*f2;
 	FILE *f;
 	char b[100],*bptr,*eptr;
 	struct stat statbuf;
-	if(cmp(f1,"-")==0)
+	if(cmp(f1,"-")==0) {
 		if(cmp(f2,"-")==0)
 			error("can't do - -","");
 		else
 			return(stdin);
+	}
 	if(stat(f1,&statbuf)==-1)
 		error("can't access ",f1);
 	if((statbuf.st_mode&S_IFMT)==S_IFDIR) {
-		for(bptr=b;*bptr= *f1++;bptr++) ;
+		for(bptr=b;(*bptr= *f1++);bptr++) ;
 		*bptr++ = '/';
 		for(eptr=f2;*eptr;eptr++)
 			if(*eptr=='/'&&eptr[1]!=0&&eptr[1]!='/')
 				f2 = eptr+1;
-		while(*bptr++= *f2++) ;
+		while((*bptr++= *f2++)) ;
 		f1 = b;
 	}
 	f = fopen(f1,"r");
@@ -247,13 +261,13 @@ char *f1,*f2;
 }
 
 
-progerr(s)
+void progerr(s)
 char *s;
 {
 	error("program error ",s);
 }
 
-error(s,t)
+void error(s,t)
 char *s,*t;
 {
 	fprintf(stderr,"diffh: %s%s\n",s,t);
@@ -261,7 +275,7 @@ char *s,*t;
 }
 
 	/*stub for resychronization beyond limits of text buf*/
-hardsynch()
+int hardsynch()
 {
 	change(n0,INF,n1,INF,"c");
 	printf("---change record omitted\n");
