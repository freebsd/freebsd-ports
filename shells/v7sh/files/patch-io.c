diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ io.c.orig io.c
--- io.c.orig	Fri Jun  4 02:51:01 2004
+++ io.c	Sat Jun 19 18:42:22 2004
@@ -8,25 +8,34 @@
  */
 
 #include	"defs.h"
-#include	"dup.h"
+
+IOPTR		iotemp;
+IOPTR		iopend;
+INT		stripflg;
+/* set by trim */
+BOOL		nosubst;
 
 
 /* ========	input output and file copying ======== */
 
-initf(fd)
+VOID	initf(fd)
 	UFD		fd;
 {
-	REG FILE	f=standin;
+	REG FILEPTR	f=standin;
 
+#if defined(SYSIII)
+	f->fdes=fd; f->fsiz=((flags&oneflg)==0 ? BUFSIZ : 1);
+#else /* V7 */
 	f->fdes=fd; f->fsiz=((flags&(oneflg|ttyflg))==0 ? BUFSIZ : 1);
+#endif
 	f->fnxt=f->fend=f->fbuf; f->feval=0; f->flin=1;
 	f->feof=FALSE;
 }
 
-estabf(s)
+INT	estabf(s)
 	REG STRING	s;
 {
-	REG FILE	f;
+	REG FILEPTR	f;
 
 	(f=standin)->fdes = -1;
 	f->fend=length(s)+(f->fnxt=s);
@@ -34,19 +43,19 @@
 	return(f->feof=(s==0));
 }
 
-push(af)
-	FILE		af;
+VOID	push(af)
+	FILEPTR		af;
 {
-	REG FILE	f;
+	REG FILEPTR	f;
 
 	(f=af)->fstak=standin;
 	f->feof=0; f->feval=0;
 	standin=f;
 }
 
-pop()
+INT	pop()
 {
-	REG FILE	f;
+	REG FILEPTR	f;
 
 	IF (f=standin)->fstak
 	THEN	IF f->fdes>=0 THEN close(f->fdes) FI
@@ -56,64 +65,66 @@
 	FI
 }
 
-chkpipe(pv)
+VOID	chkpipe(pv)
 	INT		*pv;
 {
 	IF pipe(pv)<0 ORF pv[INPIPE]<0 ORF pv[OTPIPE]<0
 	THEN	error(piperr);
+		/*NOTREACHED*/
 	FI
 }
 
-chkopen(idf)
-	STRING		idf;
+INT	chkopen(idf)
+	CSTRING		idf;
 {
 	REG INT		rc;
 
-	IF (rc=open(idf,0))<0
+	IF (rc=open(idf,O_RDONLY))<0
 	THEN	failed(idf,badopen);
-	ELSE	return(rc);
+		/*NOTREACHED*/
 	FI
+	return(rc);
 }
 
-rename(f1,f2)
+VOID	rename(f1,f2)
 	REG INT		f1, f2;
 {
 	IF f1!=f2
-	THEN	dup(f1|DUPFLG, f2);
+	THEN	dup2(f1, f2);
 		close(f1);
 		IF f2==0 THEN ioset|=1 FI
 	FI
 }
 
-create(s)
+INT	create(s)
 	STRING		s;
 {
 	REG INT		rc;
 
 	IF (rc=creat(s,0666))<0
 	THEN	failed(s,badcreate);
-	ELSE	return(rc);
+		/*NOTREACHED*/
 	FI
+	return(rc);
 }
 
-tmpfil()
+INT	tmpfil()
 {
 	itos(serial++); movstr(numbuf,tmpnam);
 	return(create(tmpout));
 }
 
-/* set by trim */
-BOOL		nosubst;
 
-copy(ioparg)
+VOID	copy(ioparg)
 	IOPTR		ioparg;
 {
-	CHAR		c, *ends;
-	REG CHAR	*cline, *clinep;
+	INT		c;
+	STRING		ends;
+	REG STRING	cline, clinep;
 	INT		fd;
 	REG IOPTR	iop;
 
-	IF iop=ioparg
+	IF (iop=ioparg)!=NIL			/* GCC */
 	THEN	copy(iop->iolst);
 		ends=mactrim(iop->ioname); IF nosubst THEN iop->iofile &= ~IODOC FI
 		fd=tmpfil();
@@ -121,13 +132,36 @@
 		iop->iolst=iotemp; iotemp=iop;
 		cline=locstak();
 
+#if defined(SYSIII)
+		IF stripflg
+		THEN	WHILE *ends=='\t' DO ends++ OD
+		FI
+#endif
 		LOOP	clinep=cline; chkpr(NL);
+#if defined(SYSIII)
+			IF stripflg
+			THEN
+				WHILE (c=(nosubst ? readc() : nextc(*ends)), !eolchar(c))
+				&& cline == clinep && c == '\t' DONE
+				WHILE (!eolchar(c))
+				DO
+					*clinep++=c;
+					c=(nosubst ? readc() : nextc(*ends));
+				OD
+			ELSE
+#endif
 			WHILE (c = (nosubst ? readc() :  nextc(*ends)),  !eolchar(c)) DO *clinep++ = c OD
+#if defined(SYSIII)
+			FI
+#endif
 			*clinep=0;
 			IF eof ORF eq(cline,ends) THEN break FI
 			*clinep++=NL;
-			write(fd,cline,clinep-cline);
+			write(fd,cline,(SIZE) (clinep-cline));
 		POOL
+#if defined(SYSIII)
+		IF stripflg THEN stripflg-- FI
+#endif
 		close(fd);
 	FI
 }
