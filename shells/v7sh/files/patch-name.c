diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ name.c.orig name.c
--- name.c.orig	Fri Jun  4 02:51:02 2004
+++ name.c	Sat Jun 19 18:42:23 2004
@@ -9,33 +9,36 @@
 
 #include	"defs.h"
 
-PROC BOOL	chkid();
+LOCAL BOOL	chkid(CSTRING);
+LOCAL VOID	namwalk(NAMPTR);
+LOCAL STRING	staknam(NAMPTR);
+LOCAL VOID	countnam(NAMPTR);
+LOCAL VOID	pushnam(NAMPTR);
+
+NAMNOD	ps2nod	= {	NIL,		NIL,		ps2name,  NIL,NIL,0},
+	fngnod	= {	NIL,		NIL,		fngname,  NIL,NIL,0},
+	pathnod = {	NIL,		NIL,		pathname, NIL,NIL,0},
+	ifsnod	= {	NIL,		NIL,		ifsname,  NIL,NIL,0},
+	ps1nod	= {	&pathnod,	&ps2nod,	ps1name,  NIL,NIL,0},
+	homenod = {	&fngnod,	&ifsnod,	homename, NIL,NIL,0},
+	mailnod = {	&homenod,	&ps1nod,	mailname, NIL,NIL,0};
 
-
-NAMNOD	ps2nod	= {	NIL,		NIL,		ps2name},
-	fngnod	= {	NIL,		NIL,		fngname},
-	pathnod = {	NIL,		NIL,		pathname},
-	ifsnod	= {	NIL,		NIL,		ifsname},
-	ps1nod	= {	&pathnod,	&ps2nod,	ps1name},
-	homenod = {	&fngnod,	&ifsnod,	homename},
-	mailnod = {	&homenod,	&ps1nod,	mailname};
-
-NAMPTR		namep = &mailnod;
+LOCAL NAMPTR	namep = &mailnod;
 
 
 /* ========	variable and string handling	======== */
 
-syslook(w,syswds)
+INT	syslook(w,syswds)
 	STRING		w;
 	SYSTAB		syswds;
 {
-	REG CHAR	first;
-	REG STRING	s;
+	REG INT		first;
+	REG CSTRING	s;
 	REG SYSPTR	syscan;
 
 	syscan=syswds; first = *w;
 
-	WHILE s=syscan->sysnam
+	WHILE (s=syscan->sysnam)!=NIL		/* GCC */
 	DO  IF first == *s
 		ANDF eq(w,s)
 	    THEN return(syscan->sysval);
@@ -45,7 +48,7 @@
 	return(0);
 }
 
-setlist(arg,xp)
+VOID	setlist(arg,xp)
 	REG ARGPTR	arg;
 	INT		xp;
 {
@@ -60,52 +63,107 @@
 	OD
 }
 
+#if defined(SYSIII)
+INT	setname(argi, xp)
+#else /* V7 */
 VOID	setname(argi, xp)
+#endif
 	STRING		argi;
 	INT		xp;
 {
+#if defined(SYSIII)
+	INT		rsflag=1;	/* local restricted flag */
+#endif
 	REG STRING	argscan=argi;
 	REG NAMPTR	n;
 
-	IF letter(*argscan)
-	THEN	WHILE alphanum(*argscan) DO argscan++ OD
+	IF letter((INT) *argscan)
+	THEN	WHILE alphanum((INT) *argscan) DO argscan++ OD
 		IF *argscan=='='
+		/* make name a cohesive string */
 		THEN	*argscan = 0;
+#if defined(SYSIII)
+		    /*	restricted stuff excluded from research	*/
+		   IF eq(argi, "SHELL") ANDF !(flags&rshflg)
+		   THEN	argscan++;
+			IF any('r', simple(argscan))
+			THEN	rsflag=0;	/* restricted shell */
+			FI
+			argscan--;
+		   FI
+		   IF eq(argi,pathname) ANDF (flags&rshflg) /* cannot set PATH */
+		   THEN	failed(argi,restricted);
+			/*NOTREACHED*/
+		   ELIF eq(argi, "SHELL") ANDF (flags&rshflg)
+		   THEN	failed(argi, restricted);
+			/*NOTREACHED*/
+		   ELSE
+#endif
 			n=lookup(argi);
 			*argscan++ = '=';
 			attrib(n, xp);
 			IF xp&N_ENVNAM
+#if defined(RENO)
+			THEN
+				/*
+				 * Importing IFS can be very dangerous
+				 */
+				IF !bcmp(argi, "IFS=", sizeof("IFS=") - 1)
+				THEN
+					UID uid;
+					IF (uid = getuid())!=geteuid() ORF !uid
+					THEN
+#if defined(SYSIII)
+						return(0);
+#else /* V7 */
+						return;
+#endif
+					FI
+				FI
+				n->namenv = n->namval = argscan;
+#else /* V7 */
 			THEN	n->namenv = n->namval = argscan;
+#endif
 			ELSE	assign(n, argscan);
 			FI
+#if defined(SYSIII)
+			return(rsflag);
+		    FI
+#else /* V7 */
 			return;
+#endif
 		FI
 	FI
 	failed(argi,notid);
+	/*NOTREACHED*/
+#if defined(SYSIII)
+	return(0);
+#endif
 }
 
-replace(a, v)
+VOID	replace(a, v)
 	REG STRING	*a;
-	STRING		v;
+	CSTRING		v;
 {
-	free(*a); *a=make(v);
+	free((BLKPTR) *a); *a=make(v);
 }
 
-dfault(n,v)
+VOID	dfault(n,v)
 	NAMPTR		n;
-	STRING		v;
+	CSTRING		v;
 {
 	IF n->namval==0
 	THEN	assign(n,v)
 	FI
 }
 
-assign(n,v)
+VOID	assign(n,v)
 	NAMPTR		n;
-	STRING		v;
+	CSTRING		v;
 {
 	IF n->namflg&N_RDONLY
 	THEN	failed(n->namid,wtfailed);
+		/*NOTREACHED*/
 	ELSE	replace(&n->namval,v);
 	FI
 }
@@ -114,18 +172,24 @@
 	STRING		*names;
 {
 	FILEBLK		fb;
-	REG FILE	f = &fb;
-	REG CHAR	c;
+	REG FILEPTR	f = &fb;
+	REG INT		c;
 	REG INT		rc=0;
 	NAMPTR		n=lookup(*names++); /* done now to avoid storage mess */
-	STKPTR		rel=relstak();
+	STKPTR		rel=(STKPTR) relstak();
 
 	push(f); initf(dup(0));
-	IF lseek(0,0L,1)==-1
+	IF lseek(0,(OFFSET) 0,SEEK_CUR)==-1
 	THEN	f->fsiz=1;
 	FI
 
+#if defined(SYSIII)
+	/*	strip leading IFS characters */
+	WHILE (any((c=nextc(0)), ifsnod.namval)) ANDF !(eolchar(c)) DONE
+	LOOP
+#else /* V7 */
 	LOOP	c=nextc(0);
+#endif
 		IF (*names ANDF any(c, ifsnod.namval)) ORF eolchar(c)
 		THEN	zerostak();
 			assign(n,absstak(rel)); setstak(rel);
@@ -135,8 +199,16 @@
 			FI
 			IF eolchar(c)
 			THEN	break;
+#if defined(SYSIII)
+			ELSE	/*	strip imbedded IFS characters	*/
+				WHILE (any((c=nextc(0)), ifsnod.namval)) ANDF
+				      !(eolchar(c)) DONE
+#endif
 			FI
 		ELSE	pushstak(c);
+#if defined(SYSIII)
+			c=nextc(0);
+#endif
 		FI
 	POOL
 	WHILE n
@@ -145,12 +217,12 @@
 	OD
 
 	IF eof THEN rc=1 FI
-	lseek(0, (long)(f->fnxt-f->fend), 1);
+	lseek(0, (OFFSET) (f->fnxt-f->fend), SEEK_CUR);
 	pop();
 	return(rc);
 }
 
-assnum(p, i)
+VOID	assnum(p, i)
 	STRING		*p;
 	INT		i;
 {
@@ -158,27 +230,28 @@
 }
 
 STRING	make(v)
-	STRING		v;
+	CSTRING		v;
 {
 	REG STRING	p;
 
 	IF v
-	THEN	movstr(v,p=alloc(length(v)));
+	THEN	movstr(v,p=(STRING) alloc((POS) length(v)));
 		return(p);
 	ELSE	return(0);
 	FI
 }
 
 
-NAMPTR		lookup(nam)
-	REG STRING	nam;
+NAMPTR	lookup(nam)
+	REG CSTRING	nam;
 {
 	REG NAMPTR	nscan=namep;
-	REG NAMPTR	*prev;
+	REG NAMPTR	*prev=NIL;		/* GCC */
 	INT		LR;
 
 	IF !chkid(nam)
 	THEN	failed(nam,notid);
+		/*NOTREACHED*/
 	FI
 	WHILE nscan
 	DO	IF (LR=cf(nam,nscan->namid))==0
@@ -191,7 +264,7 @@
 	OD
 
 	/* add name node */
-	nscan=alloc(sizeof *nscan);
+	nscan=(NAMPTR) alloc(sizeof *nscan);
 	nscan->namlft=nscan->namrgt=NIL;
 	nscan->namid=make(nam);
 	nscan->namval=0; nscan->namflg=N_DEFAULT; nscan->namenv=0;
@@ -199,14 +272,14 @@
 }
 
 LOCAL BOOL	chkid(nam)
-	STRING		nam;
+	CSTRING		nam;
 {
-	REG CHAR *	cp=nam;
+	REG CSTRING	cp=nam;
 
-	IF !letter(*cp)
+	IF !letter((INT) *cp)
 	THEN	return(FALSE);
 	ELSE	WHILE *++cp
-		DO IF !alphanum(*cp)
+		DO IF !alphanum((INT) *cp)
 		   THEN	return(FALSE);
 		   FI
 		OD
@@ -214,9 +287,10 @@
 	return(TRUE);
 }
 
-LOCAL VOID (*namfn)();
-namscan(fn)
-	VOID		(*fn)();
+LOCAL VOID (*namfn)(NAMPTR);
+
+VOID	namscan(fn)
+	VOID		(*fn)(NAMPTR);
 {
 	namfn=fn;
 	namwalk(namep);
@@ -238,7 +312,7 @@
 	REG STRING	s;
 
 	sigchk();
-	IF s=n->namval
+	IF (s=n->namval)!=NIL			/* GCC */
 	THEN	prs(n->namid);
 		prc('='); prs(s);
 		newline();
@@ -253,16 +327,16 @@
 	p=movstr(n->namid,staktop);
 	p=movstr("=",p);
 	p=movstr(n->namval,p);
-	return(getstak(p+1-ADR(stakbot)));
+	return(getstak((POS) (p+1-ADR(stakbot))));
 }
 
 VOID	exname(n)
 	REG NAMPTR	n;
 {
 	IF n->namflg&N_EXPORT
-	THEN	free(n->namenv);
+	THEN	free((BLKPTR) n->namenv);
 		n->namenv = make(n->namval);
-	ELSE	free(n->namval);
+	ELSE	free((BLKPTR) n->namval);
 		n->namval = make(n->namenv);
 	FI
 }
@@ -281,6 +355,16 @@
 	FI
 }
 
+#if defined(SYSIII)
+INT	getenv()
+{
+	INT	rsflag=1;	/* local restricted flag */
+	REG STRING	*e=environ;
+
+	WHILE *e DO rsflag=setname(*e++, N_ENVNAM) & rsflag OD
+	return(rsflag);
+}
+#else /* V7 */
 VOID	getenv()
 {
 	REG STRING	*e=environ;
@@ -288,18 +372,20 @@
 	WHILE *e
 	DO setname(*e++, N_ENVNAM) OD
 }
+#endif
 
-LOCAL INT	namec;
+LOCAL POS	namec;
 
-VOID	countnam(n)
+LOCAL VOID	countnam(n)
 	NAMPTR		n;
 {
+	n=n;					/* GCC */
 	namec++;
 }
 
 LOCAL STRING 	*argnam;
 
-VOID	pushnam(n)
+LOCAL VOID	pushnam(n)
 	NAMPTR		n;
 {
 	IF n->namval
@@ -313,7 +399,7 @@
 
 	namec=0;
 	namscan(countnam);
-	argnam = er = getstak(namec*BYTESPERWORD+BYTESPERWORD);
+	argnam = er = (STRING *) getstak(namec*BYTESPERWORD+BYTESPERWORD);
 	namscan(pushnam);
 	*argnam++ = 0;
 	return(er);
