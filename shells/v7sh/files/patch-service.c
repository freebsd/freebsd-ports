diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ service.c.orig service.c
--- service.c.orig	Fri Jun  4 02:51:02 2004
+++ service.c	Sat Jun 19 18:42:24 2004
@@ -10,20 +10,15 @@
 #include	"defs.h"
 
 
-PROC VOID	gsort();
 
 #define ARGMK	01
 
-INT		errno;
-STRING		sysmsg[];
-
-/* fault handling */
-#define ENOMEM	12
-#define ENOEXEC 8
-#define E2BIG	7
-#define ENOENT	2
-#define ETXTBSY 26
-
+LOCAL CSTRING	execs(CSTRING, STRING *);
+LOCAL VOID	gsort(STRING *, STRING *);
+LOCAL INT	split(STRING);
+#if defined(GOCSH) /* RENO */
+LOCAL VOID	gocsh(STRING *, STRING, STRING *);
+#endif
 
 
 /* service routines for `execute' */
@@ -32,7 +27,7 @@
 	IOPTR		iop;
 {
 	REG STRING	ion;
-	REG INT		iof, fd;
+	REG INT		iof, fd=-1;		/* GCC */
 
 	IF iop
 	THEN	iof=iop->iofile;
@@ -47,15 +42,23 @@
 					close(iof&IOUFD);
 				ELIF (fd=stoi(ion))>=USERIO
 				THEN	failed(ion,badfile);
+					/*NOTREACHED*/
 				ELSE	fd=dup(fd);
 				FI
 			ELIF (iof&IOPUT)==0
 			THEN	fd=chkopen(ion);
 			ELIF flags&rshflg
 			THEN	failed(ion,restricted);
-			ELIF iof&IOAPP ANDF (fd=open(ion,1))>=0
-			THEN	lseek(fd, 0L, 2);
+				/*NOTREACHED*/
+#if defined(RENO)
+			ELIF (iof&IOAPP)==0 ORF
+			     (fd=open(ion,O_WRONLY|O_APPEND))<0
+			THEN	fd=create(ion);
+#else /* V7 */
+			ELIF iof&IOAPP ANDF (fd=open(ion,O_WRONLY))>=0
+			THEN	lseek(fd, (OFFSET) 0, SEEK_END);
 			ELSE	fd=create(ion);
+#endif
 			FI
 			IF fd>=0
 			THEN	rename(fd,iof&IOUFD);
@@ -65,38 +68,44 @@
 	FI
 }
 
-STRING	getpath(s)
-	STRING		s;
+CSTRING	getpath(s)
+	CSTRING		s;
 {
-	REG STRING	path;
+	REG CSTRING	path;
+
+#if defined(SYSIII)
+	IF any('/',s) ORF any(('/'|QUOTE),s)
+#else /* V7 */
 	IF any('/',s)
+#endif
 	THEN	IF flags&rshflg
 		THEN	failed(s, restricted);
-		ELSE	return(nullstr);
+			/*NOTREACHED*/
 		FI
 	ELIF (path = pathnod.namval)==0
 	THEN	return(defpath);
 	ELSE	return(cpystak(path));
 	FI
+	return(nullstr);
 }
 
 INT	pathopen(path, name)
-	REG STRING	path, name;
+	REG CSTRING	path, name;
 {
 	REG UFD		f;
 
 	REP path=catpath(path,name);
-	PER (f=open(curstak(),0))<0 ANDF path DONE
+	PER (f=open(curstak(),O_RDONLY))<0 ANDF path DONE
 	return(f);
 }
 
-STRING	catpath(path,name)
-	REG STRING	path;
-	STRING		name;
+CSTRING	catpath(path,name)
+	REG CSTRING	path;
+	CSTRING		name;
 {
 	/* leaves result on top of stack */
-	REG STRING	scanp = path,
-			argp = locstak();
+	REG CSTRING	scanp = path;
+	REG STRING	argp = locstak();
 
 	WHILE *scanp ANDF *scanp!=COLON DO *argp++ = *scanp++ OD
 	IF scanp!=path THEN *argp++='/' FI
@@ -106,29 +115,32 @@
 	return(path);
 }
 
-LOCAL STRING	xecmsg;
+LOCAL CSTRING	xecmsg;
 LOCAL STRING	*xecenv;
 
 VOID	execa(at)
 	STRING		at[];
 {
-	REG STRING	path;
+	REG CSTRING	path;
 	REG STRING	*t = at;
 
 	IF (flags&noexec)==0
 	THEN	xecmsg=notfound; path=getpath(*t);
 		namscan(exname);
 		xecenv=setenv();
-		WHILE path=execs(path,t) DONE
+		WHILE (path=execs(path,t))!=NIL DONE	/* GCC */
 		failed(*t,xecmsg);
+		/*NOTREACHED*/
 	FI
 }
 
-LOCAL STRING	execs(ap,t)
-	STRING		ap;
+
+LOCAL CSTRING	execs(ap,t)
+	CSTRING		ap;
 	REG STRING	t[];
 {
-	REG STRING	p, prefix;
+	REG STRING	p;
+	REG CSTRING	prefix;
 
 	prefix=catpath(ap,t[0]);
 	trim(p=curstak());
@@ -145,32 +157,67 @@
 		close(output); output=2;
 		input=chkopen(p);
 
+#if defined(GOCSH) /* RENO */
+		/* band aid to get csh... 2/26/79 */
+		BEGIN
+			CHAR c;
+
+			IF !isatty(input)
+			THEN	read(input, &c, 1);
+				IF c == '#' THEN gocsh(t, p, xecenv) FI
+				lseek(input, (OFFSET) 0, SEEK_SET);
+			FI
+		END
+#endif
+
 		/* set up new args */
 		setargs(t);
 		longjmp(subshell,1);
+		/*NOTREACHED*/
 
 	    case ENOMEM:
 		failed(p,toobig);
+		/*NOTREACHED*/
 
 	    case E2BIG:
 		failed(p,arglist);
+		/*NOTREACHED*/
 
 	    case ETXTBSY:
 		failed(p,txtbsy);
+		/*NOTREACHED*/
 
 	    default:
 		xecmsg=badexec;
+		/*FALLTHROUGH*/
+
 	    case ENOENT:
 		return(prefix);
 	ENDSW
 }
 
+#if defined(GOCSH) /* RENO */
+LOCAL VOID	gocsh(t, cp, xecenv)
+	REG STRING *t, cp, *xecenv;
+{
+	STRING *newt[1000];
+	REG STRING *p;
+	REG INT i;
+
+	FOR i = 0; t[i]; i++ DO newt[i+1] = t[i] OD
+	newt[i+1] = 0;
+	newt[0] = _PATH_CSHELL;
+	newt[1] = cp;
+	execve(_PATH_CSHELL, newt, xecenv);
+}
+#endif
+
 /* for processes to be waited for */
 #define MAXP 20
 LOCAL INT	pwlist[MAXP];
 LOCAL INT	pwc;
 
-postclr()
+VOID	postclr()
 {
 	REG INT		*pw = pwlist;
 
@@ -194,8 +241,13 @@
 	FI
 }
 
+#if defined(SYSIII)
+VOID	await(i, bckg)
+	INT		i, bckg;
+#else /* V7 */
 VOID	await(i)
 	INT		i;
+#endif
 {
 	INT		rc=0, wx=0;
 	INT		w;
@@ -206,28 +258,65 @@
 	DO	REG INT		p;
 		REG INT		sig;
 		INT		w_hi;
+#if defined(SYSIII)
+		INT		found = 0;
+#endif
 
 		BEGIN
 		   REG INT	*pw=pwlist;
+#if defined(RENO)
+		   IF setjmp(INTbuf) == 0
+		   THEN	trapjmp[INTR] = 1;
+#endif
 		   p=wait(&w);
+#if defined(SYSIII)
+			IF wasintr THEN
+				wasintr = 0;
+				IF bckg THEN break; FI
+			FI
+#endif
+#if defined(RENO)
+		   ELSE	p = -1;
+		   FI
+		   trapjmp[INTR] = 0;
+#endif
 		   WHILE pw <= &pwlist[ipwc]
 		   DO IF *pw==p
 		      THEN *pw=0; pwc--;
+#if defined(SYSIII)
+			   found++;
+#endif
 		      ELSE pw++;
 		      FI
 		   OD
 		END
 
+#if defined(SYSIII)
+		IF p == -1
+		THEN	IF bckg THEN
+				REG INT *pw =pwlist;
+				WHILE pw <= &pwlist[ipwc] ANDF i != *pw
+				DO pw++; OD
+				IF i == *pw THEN *pw = 0; pwc-- FI
+			FI
+			continue
+		FI
+#else /* V7 */
 		IF p == -1 THEN continue FI
+#endif
 
 		w_hi = (w>>8)&LOBYTE;
 
-		IF sig = w&0177
+		IF (sig = w&0177)!=0		/* GCC */
 		THEN	IF sig == 0177	/* ptrace! return */
 			THEN	prs("ptrace: ");
 				sig = w_hi;
 			FI
+#if defined(RENO)
+			IF sig < num_sysmsg ANDF sysmsg[sig]
+#else /* V7 */
 			IF sysmsg[sig]
+#endif
 			THEN	IF i!=p ORF (flags&prompt)==0 THEN prp(); prn(p); blank() FI
 				prs(sysmsg[sig]);
 				IF w&0200 THEN prs(coredump) FI
@@ -235,29 +324,35 @@
 			newline();
 		FI
 
+#if defined(SYSIII)
+		IF rc==0 ANDF found != 0
+#else /* V7 */
 		IF rc==0
+#endif
 		THEN	rc = (sig ? sig|SIGFLG : w_hi);
 		FI
 		wx |= w;
+#if defined(SYSIII)
+		IF p == i THEN break FI
+#endif
 	OD
 
 	IF wx ANDF flags&errflg
 	THEN	exitsh(rc);
+		/*NOTREACHED*/
 	FI
 	exitval=rc; exitset();
 }
 
-BOOL		nosubst;
-
-trim(at)
+VOID	trim(at)
 	STRING		at;
 {
 	REG STRING	p;
-	REG CHAR	c;
-	REG CHAR	q=0;
+	REG INT		c;
+	REG INT		q=0;
 
-	IF p=at
-	THEN	WHILE c = *p
+	IF (p=at)!=NIL				/* GCC */
+	THEN	WHILE (c = *p)!=0		/* GCC */
 		DO *p++=c&STRIP; q |= c OD
 	FI
 	nosubst=q&QUOTE;
@@ -274,14 +369,15 @@
 STRING	*scan(argn)
 	INT		argn;
 {
-	REG ARGPTR	argp = Rcheat(gchain)&~ARGMK;
+	REG ARGPTR	argp = (ARGPTR) (Rcheat(gchain)&~ARGMK);
 	REG STRING	*comargn, *comargm;
 
-	comargn=getstak(BYTESPERWORD*argn+BYTESPERWORD); comargm = comargn += argn; *comargn = ENDARGS;
+	comargn=(STRING *) getstak(BYTESPERWORD*argn+BYTESPERWORD);
+	comargm = comargn += argn; *comargn = ENDARGS;
 
 	WHILE argp
 	DO	*--comargn = argp->argval;
-		IF argp = argp->argnxt
+		IF (argp = argp->argnxt)!=NIL	/* GCC */
 		THEN trim(*comargn);
 		FI
 		IF argp==0 ORF Rcheat(argp)&ARGMK
@@ -289,7 +385,7 @@
 			comargm = comargn;
 		FI
 		/* Lcheat(argp) &= ~ARGMK; */
-		argp = Rcheat(argp)&~ARGMK;
+		argp = (ARGPTR) (Rcheat(argp)&~ARGMK);
 	OD
 	return(comargn);
 }
@@ -327,7 +423,7 @@
 	REG INT		count=0;
 	REG COMPTR	c;
 
-	IF c=ac
+	IF (c=ac)!=NIL				/* GCC */
 	THEN	argp=c->comarg;
 		WHILE argp
 		DO	count += split(macro(argp->argval));
@@ -338,16 +434,17 @@
 }
 
 LOCAL INT	split(s)
+	/* blank interpretation routine */
 	REG STRING	s;
 {
 	REG STRING	argp;
 	REG INT		c;
 	INT		count=0;
 
-	LOOP	sigchk(); argp=locstak()+BYTESPERWORD;
+	LOOP	sigchk(); argp=(STRING) (locstak()+BYTESPERWORD);
 		WHILE (c = *s++, !any(c,ifsnod.namval) && c)
 		DO *argp++ = c OD
-		IF argp==staktop+BYTESPERWORD
+		IF argp==(STRING)(staktop+BYTESPERWORD)
 		THEN	IF c
 			THEN	continue;
 			ELSE	return(count);
@@ -355,11 +452,27 @@
 		ELIF c==0
 		THEN	s--;
 		FI
-		IF c=expand((argp=endstak(argp))->argval,0)
+		/* file name generation */
+		IF (c=expand(((ARGPTR) (argp=(STRING) endstak(argp)))->argval,0))!=0 /* GCC */
 		THEN	count += c;
 		ELSE	/* assign(&fngnod, argp->argval); */
-			makearg(argp); count++;
+			makearg((ARGPTR) argp); count++;
 		FI
 		Lcheat(gchain) |= ARGMK;
 	POOL
 }
+
+#if defined(SYSIII)
+CSTRING	simple(s)
+	CSTRING		s;
+{
+	CSTRING		sname=s;
+
+	LOOP
+		IF any('/', sname)
+		THEN	WHILE *sname++ != '/' DONE
+		ELSE	return(sname);
+		FI
+	POOL
+}
+#endif
