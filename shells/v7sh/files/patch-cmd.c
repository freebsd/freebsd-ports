diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ cmd.c.orig cmd.c
--- cmd.c.orig	Fri Jun  4 02:51:01 2004
+++ cmd.c	Sat Jun 19 18:42:21 2004
@@ -10,17 +10,17 @@
 #include	"defs.h"
 #include	"sym.h"
 
-PROC IOPTR	inout();
-PROC VOID	chkword();
-PROC VOID	chksym();
-PROC TREPTR	term();
-PROC TREPTR	makelist();
-PROC TREPTR	list();
-PROC REGPTR	syncase();
-PROC TREPTR	item();
-PROC VOID	skipnl();
-PROC VOID	prsym();
-PROC VOID	synbad();
+LOCAL TREPTR	makelist(INT,TREPTR,TREPTR);
+LOCAL TREPTR	list(INT);
+LOCAL TREPTR	term(INT);
+LOCAL REGPTR	syncase(INT);
+LOCAL TREPTR	item(BOOL);
+LOCAL INT	skipnl(VOID);
+LOCAL IOPTR	inout(IOPTR);
+LOCAL VOID	chkword(VOID);
+LOCAL VOID	chksym(INT);
+LOCAL VOID	prsym(INT);
+LOCAL VOID	synbad(VOID);
 
 
 /* ========	command line decoding	========*/
@@ -34,8 +34,10 @@
 {
 	REG TREPTR	t;
 
-	t=getstak(FORKTYPE);
-	t->forktyp=flgs|TFORK; t->forktre=i; t->forkio=0;
+	t=(TREPTR) getstak(FORKTYPE);
+	t->forknod.forktyp=flgs|TFORK;
+	t->forknod.forktre=i;
+	t->forknod.forkio=0;
 	return(t);
 }
 
@@ -43,13 +45,14 @@
 	INT		type;
 	TREPTR		i, r;
 {
-	REG TREPTR	t;
+	REG TREPTR	t=NIL;			/* GCC */
 
 	IF i==0 ORF r==0
 	THEN	synbad();
-	ELSE	t = getstak(LSTTYPE);
-		t->lsttyp = type;
-		t->lstlef = i; t->lstrit = r;
+	ELSE	t=(TREPTR) getstak(LSTTYPE);
+		t->lstnod.lsttyp = type;
+		t->lstnod.lstlef = i;
+		t->lstnod.lstrit = r;
 	FI
 	return(t);
 }
@@ -85,10 +88,15 @@
 		THEN	i = makefork(FINT|FPRS|FAMP, i);
 		ELSE	synbad();
 		FI
+		/*FALLTHROUGH*/
 
 	    case ';':
-		IF e=cmd(sym,flg|MTFLG)
+		IF (e=cmd(sym,flg|MTFLG))!=NIL	/* GCC */
 		THEN	i=makelist(TLST, i, e);
+#if defined(SYSIII)
+		ELIF	i == 0
+		THEN	synbad();
+#endif
 		FI
 		break;
 
@@ -96,6 +104,7 @@
 		IF sym==NL
 		THEN	break;
 		FI
+		/*FALLTHROUGH*/
 
 	    default:
 		IF sym
@@ -114,6 +123,7 @@
  */
 
 LOCAL TREPTR	list(flg)
+	INT		flg;
 {
 	REG TREPTR	r;
 	REG INT		b;
@@ -132,6 +142,7 @@
  */
 
 LOCAL TREPTR	term(flg)
+	INT		flg;
 {
 	REG TREPTR	t;
 
@@ -153,7 +164,7 @@
 	skipnl();
 	IF wdval==esym
 	THEN	return(0);
-	ELSE	REG REGPTR	r=getstak(REGTYPE);
+	ELSE	REG REGPTR	r=(REGPTR) getstak(REGTYPE);
 		r->regptr=0;
 		LOOP wdarg->argnxt=r->regptr;
 		     r->regptr=wdarg;
@@ -201,54 +212,54 @@
 
 	    case CASYM:
 		BEGIN
-		   t=getstak(SWTYPE);
+		   t=(TREPTR) getstak(SWTYPE);
 		   chkword();
-		   t->swarg=wdarg->argval;
+		   t->swnod.swarg=wdarg->argval;
 		   skipnl(); chksym(INSYM|BRSYM);
-		   t->swlst=syncase(wdval==INSYM?ESSYM:KTSYM);
-		   t->swtyp=TSW;
+		   t->swnod.swlst=syncase(wdval==INSYM?ESSYM:KTSYM);
+		   t->swnod.swtyp=TSW;
 		   break;
 		END
 
 	    case IFSYM:
 		BEGIN
 		   REG INT	w;
-		   t=getstak(IFTYPE);
-		   t->iftyp=TIF;
-		   t->iftre=cmd(THSYM,NLFLG);
-		   t->thtre=cmd(ELSYM|FISYM|EFSYM,NLFLG);
-		   t->eltre=((w=wdval)==ELSYM ? cmd(FISYM,NLFLG) : (w==EFSYM ? (wdval=IFSYM, item(0)) : 0));
+		   t=(TREPTR) getstak(IFTYPE);
+		   t->ifnod.iftyp=TIF;
+		   t->ifnod.iftre=cmd(THSYM,NLFLG);
+		   t->ifnod.thtre=cmd(ELSYM|FISYM|EFSYM,NLFLG);
+		   t->ifnod.eltre=((w=wdval)==ELSYM ? cmd(FISYM,NLFLG) : (w==EFSYM ? (wdval=IFSYM, item(0)) : 0));
 		   IF w==EFSYM THEN return(t) FI
 		   break;
 		END
 
 	    case FORSYM:
 		BEGIN
-		   t=getstak(FORTYPE);
-		   t->fortyp=TFOR;
-		   t->forlst=0;
+		   t=(TREPTR) getstak(FORTYPE);
+		   t->fornod.fortyp=TFOR;
+		   t->fornod.forlst=0;
 		   chkword();
-		   t->fornam=wdarg->argval;
+		   t->fornod.fornam=wdarg->argval;
 		   IF skipnl()==INSYM
 		   THEN	chkword();
-			t->forlst=item(0);
+			t->fornod.forlst=(COMPTR) item(0);
 			IF wdval!=NL ANDF wdval!=';'
 			THEN	synbad();
 			FI
 			chkpr(wdval); skipnl();
 		   FI
 		   chksym(DOSYM|BRSYM);
-		   t->fortre=cmd(wdval==DOSYM?ODSYM:KTSYM,NLFLG);
+		   t->fornod.fortre=cmd(wdval==DOSYM?ODSYM:KTSYM,NLFLG);
 		   break;
 		END
 
 	    case WHSYM:
 	    case UNSYM:
 		BEGIN
-		   t=getstak(WHTYPE);
-		   t->whtyp=(wdval==WHSYM ? TWH : TUN);
-		   t->whtre = cmd(DOSYM,NLFLG);
-		   t->dotre = cmd(ODSYM,NLFLG);
+		   t=(TREPTR) getstak(WHTYPE);
+		   t->whnod.whtyp=(wdval==WHSYM ? TWH : TUN);
+		   t->whnod.whtre = cmd(DOSYM,NLFLG);
+		   t->whnod.dotre = cmd(ODSYM,NLFLG);
 		   break;
 		END
 
@@ -259,10 +270,10 @@
 	    case '(':
 		BEGIN
 		   REG PARPTR	 p;
-		   p=getstak(PARTYPE);
+		   p=(PARPTR) getstak(PARTYPE);
 		   p->partre=cmd(')',NLFLG);
 		   p->partyp=TPAR;
-		   t=makefork(0,p);
+		   t=makefork(0,(TREPTR) p);
 		   break;
 		END
 
@@ -270,6 +281,7 @@
 		IF io==0
 		THEN	return(0);
 		FI
+		/*FALLTHROUGH*/
 
 	    case 0:
 		BEGIN
@@ -277,35 +289,37 @@
 		   REG ARGPTR	*argtail;
 		   REG ARGPTR	*argset=0;
 		   INT		keywd=1;
-		   t=getstak(COMTYPE);
-		   t->comio=io; /*initial io chain*/
-		   argtail = &(t->comarg);
+		   t=(TREPTR) getstak(COMTYPE);
+		   t->comnod.comio=io; /*initial io chain*/
+		   argtail = &(t->comnod.comarg);
 		   WHILE wdval==0
 		   DO	argp = wdarg;
 			IF wdset ANDF keywd
-			THEN	argp->argnxt=argset; argset=argp;
+			THEN	argp->argnxt=(ARGPTR) argset; argset=(ARGPTR *) argp;
 			ELSE	*argtail=argp; argtail = &(argp->argnxt); keywd=flags&keyflg;
 			FI
 			word();
 			IF flag
-			THEN t->comio=inout(t->comio);
+			THEN t->comnod.comio=inout(t->comnod.comio);
 			FI
 		   OD
 
-		   t->comtyp=TCOM; t->comset=argset; *argtail=0;
+		   t->comnod.comtyp=TCOM;
+		   t->comnod.comset=(ARGPTR) argset;
+		   *argtail=0;
 		   return(t);
 		END
 
 	ENDSW
 	reserv++; word();
-	IF io=inout(io)
-	THEN	t=makefork(0,t); t->treio=io;
+	IF (io=inout(io))!=NIL
+	THEN	t=makefork(0,t); t->treio.treio=io;
 	FI
 	return(t);
 }
 
 
-LOCAL VOID	skipnl()
+LOCAL INT	skipnl()
 {
 	WHILE (reserv++, word()==NL) DO chkpr(NL) OD
 	return(wdval);
@@ -316,27 +330,33 @@
 {
 	REG INT		iof;
 	REG IOPTR	iop;
-	REG CHAR	c;
+	REG INT		c;
 
 	iof=wdnum;
 
 	SWITCH wdval IN
 
 	    case DOCSYM:
+		/*	<<	*/
 		iof |= IODOC; break;
+		/*FALLTHROUGH*/
 
 	    case APPSYM:
+	        /*	>>	*/
 	    case '>':
 		IF wdnum==0 THEN iof |= 1 FI
 		iof |= IOPUT;
 		IF wdval==APPSYM
 		THEN	iof |= IOAPP; break;
 		FI
+		/*FALLTHROUGH*/
 
 	    case '<':
 		IF (c=nextc(0))=='&'
 		THEN	iof |= IOMOV;
 		ELIF c=='>'
+		/*	<> is open for read and write	*/
+		/*	unadvertised feature		*/
 		THEN	iof |= IORDW;
 		ELSE	peekc=c|MARK;
 		FI
@@ -347,7 +367,7 @@
 	ENDSW
 
 	chkword();
-	iop=getstak(IOTYPE); iop->ioname=wdarg->argval; iop->iofile=iof;
+	iop=(IOPTR) getstak(IOTYPE); iop->ioname=wdarg->argval; iop->iofile=iof;
 	IF iof&IODOC
 	THEN iop->iolst=iopend; iopend=iop;
 	FI
@@ -363,6 +383,7 @@
 }
 
 LOCAL VOID	chksym(sym)
+	INT		sym;
 {
 	REG INT		x = sym&wdval;
 	IF ((x&SYMFLG) ? x : sym) != wdval
@@ -371,6 +392,7 @@
 }
 
 LOCAL VOID	prsym(sym)
+	INT		sym;
 {
 	IF sym&SYMFLG
 	THEN	REG SYSPTR	sp=reserved;
@@ -382,7 +404,7 @@
 	THEN	prs(endoffile);
 	ELSE	IF sym&SYMREP THEN prc(sym) FI
 		IF sym==NL
-		THEN	prs("newline");
+		THEN	prs(endofline);
 		ELSE	prc(sym);
 		FI
 	FI
@@ -392,7 +414,7 @@
 {
 	prp(); prs(synmsg);
 	IF (flags&ttyflg)==0
-	THEN	prs(atline); prn(standin->flin);
+	THEN	prs(atline); prn((INT) standin->flin);
 	FI
 	prs(colon);
 	prc(LQ);
@@ -403,4 +425,5 @@
 	prc(RQ); prs(unexpected);
 	newline();
 	exitsh(SYNBAD);
+	/*NOTREACHED*/
 }
