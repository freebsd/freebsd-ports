diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ main.c.orig main.c
--- main.c.orig	Fri Jun  4 02:51:01 2004
+++ main.c	Sat Jun 19 18:42:23 2004
@@ -8,30 +8,43 @@
  */
 
 #include	"defs.h"
-#include	"dup.h"
 #include	"sym.h"
 #include	"timeout.h"
-#include	<sys/types.h>
-#include	<sys/stat.h>
-#include	<sgtty.h>
-
-UFD		output = 2;
-LOCAL BOOL	beenhere = FALSE;
-CHAR		tmpout[20] = "/tmp/sh-";
-FILEBLK		stdfile;
-FILE		standin = &stdfile;
+#include	"pathnames.h"
+#ifdef stupid
 #include	<execargs.h>
+#endif
 
-PROC VOID	exfile();
+LOCAL VOID	exfile(BOOL);
+LOCAL VOID	Ldup(INT, INT);
 
+LOCAL BOOL	beenhere = FALSE;
+LOCAL FILEBLK	stdfile;
 
+UFD		output = 2;
+CHAR		tmpout[20] = _PATH_TMPOUT;
+STRING		tmpnam;
+FILEPTR		standin = &stdfile;
+INT		dolc;
+STRING		*dolv;
+STRING		dolladr;
+STRING		cmdadr;
+STRING		pidadr;
+STRING		comdiv;
+INT		flags;
+INT		serial;
+jmp_buf		subshell;
+jmp_buf		errshell;
 
 
-main(c, v)
+INT	main(c, v)
 	INT		c;
 	STRING		v[];
 {
 	REG INT		rflag=ttyflg;
+#if defined(SYSIII)
+	INT		rsflag=1;	/* local restricted flag */
+#endif
 
 	/* initialise storage allocation */
 	stdsigs();
@@ -39,42 +52,72 @@
 	addblok((POS)0);
 
 	/* set names from userenv */
+#if !defined(SYSIII)
 	getenv();
+#else /* SYSIII */
+	/* 'rsflag' is non-zero if SHELL variable is
+	   set in environment and contains an 'r' in
+	   the simple file part of the value.	*/
+	rsflag=getenv();
 
 	/* look for restricted */
-/*	IF c>0 ANDF any('r', *v) THEN rflag=0 FI */
-
+	/* a shell is also restricted if argv(0) has
+	   an 'r' in its simple name	*/
+	IF c>0 ANDF any('r', simple(*v)) THEN rflag=0 FI
+#endif
 	/* look for options */
+	/* dolc is $# */
 	dolc=options(c,v);
 	IF dolc<2 THEN flags |= stdflg FI
+#if defined(SYSIII)
+	IF dolc < 2
+	THEN	REG STRING flagc = flagadr;
+		WHILE *flagc DO flagc++ OD
+		*flagc = STDFLG;
+	FI
+#endif
 	IF (flags&stdflg)==0
 	THEN	dolc--;
 	FI
 	dolv=v+c-dolc; dolc--;
 
 	/* return here for shell file execution */
+	/* but not for parenthesis subshells	*/
 	setjmp(subshell);
 
-	/* number of positional parameters */
+	/* number of positional parameters '$#' */
 	assnum(&dolladr,dolc);
+	/* comadr is $0 */
 	cmdadr=dolv[0];
 
-	/* set pidname */
+	/* set pidname '$$' */
 	assnum(&pidadr, getpid());
 
 	/* set up temp file names */
 	settmp();
 
-	/* default ifs */
+	/* default internal field separators - $IFS */
 	dfault(&ifsnod, sptbnl);
 
 	IF (beenhere++)==FALSE
 	THEN	/* ? profile */
+#if defined(SYSIII)
+		IF *simple(cmdadr) == '-'
+		THEN	IF (input=pathopen(nullstr, sysprofile))>=0
+			THEN	exfile(rflag);	/* file exists */
+			FI
+			IF (input=pathopen(homenod.namenv, profile))>=0
+			THEN	exfile(rflag); flags &= ~ttyflg;
+			FI
+		FI
+		IF rsflag==0 ORF rflag==0 THEN flags |= rshflg FI
+#else /* V7 */
 		IF *cmdadr=='-'
 		    ANDF (input=pathopen(nullstr, profile))>=0
 		THEN	exfile(rflag); flags &= ~ttyflg;
 		FI
 		IF rflag==0 THEN flags |= rshflg FI
+#endif
 
 		/* open input file if specified */
 		IF comdiv
@@ -82,18 +125,22 @@
 		ELSE	input=((flags&stdflg) ? 0 : chkopen(cmdadr));
 			comdiv--;
 		FI
-	ELSE	*execargs=dolv;	/* for `ps' cmd */
+#ifdef stupid
+	ELSE	*execargs=(STRING) dolv;	/* for `ps' cmd */
+#endif
 	FI
 
 	exfile(0);
 	done();
+	/*NOTREACHED*/
+	return(exitval);			/* GCC */
 }
 
 LOCAL VOID	exfile(prof)
-BOOL		prof;
+	BOOL		prof;
 {
-	REG L_INT	mailtime = 0;
-	REG INT		userid;
+	REG TIME	mailtime = 0;
+	REG UID		userid;
 	struct stat	statb;
 
 	/* move input */
@@ -108,10 +155,14 @@
 		output=OTIO;
 	FI
 
+#if defined(SYSIII)
+	userid=geteuid();
+#else /* V7 */
 	userid=getuid();
+#endif
 
 	/* decide whether interactive */
-	IF (flags&intflg) ORF ((flags&oneflg)==0 ANDF gtty(output,&statb)==0 ANDF gtty(input,&statb)==0)
+	IF (flags&intflg) ORF ((flags&oneflg)==0 ANDF isatty(output) ANDF isatty(input))
 	THEN	dfault(&ps1nod, (userid?stdprompt:supprompt));
 		dfault(&ps2nod, readmsg);
 		flags |= ttyflg|prompt; ignsig(KILL);
@@ -132,43 +183,63 @@
 		exitset();
 		IF (flags&prompt) ANDF standin->fstak==0 ANDF !eof
 		THEN	IF mailnod.namval
+#if defined(SYSIII)
+			THEN	IF stat(mailnod.namval,&statb)>=0
+				THEN	IF statb.st_size
+					   ANDF mailtime
+					   ANDF (statb.st_mtime != mailtime)
+					THEN	prs(mailmsg)
+					FI
+					mailtime=statb.st_mtime;
+				ELIF mailtime==0
+				THEN	mailtime=1
+				FI
+			FI
+#else /* V7 */
 			    ANDF stat(mailnod.namval,&statb)>=0 ANDF statb.st_size
 			    ANDF (statb.st_mtime != mailtime)
 			    ANDF mailtime
 			THEN	prs(mailmsg)
 			FI
 			mailtime=statb.st_mtime;
+#endif
+#if TIMEOUT > 0
 			prs(ps1nod.namval); alarm(TIMEOUT); flags |= waiting;
+#else /* !TIMEOUT */
+			prs(ps1nod.namval);
+#endif
 		FI
 
 		trapnote=0; peekc=readc();
 		IF eof
 		THEN	return;
 		FI
+#if TIMEOUT > 0
 		alarm(0); flags &= ~waiting;
-		execute(cmd(NL,MTFLG),0);
+#endif
+		execute(cmd(NL,MTFLG),0,0,0);
 		eof |= (flags&oneflg);
 	POOL
 }
 
-chkpr(eor)
-char eor;
+VOID	chkpr(eor)
+	INT	eor;
 {
 	IF (flags&prompt) ANDF standin->fstak==0 ANDF eor==NL
 	THEN	prs(ps2nod.namval);
 	FI
 }
 
-settmp()
+VOID	settmp()
 {
 	itos(getpid()); serial=0;
 	tmpnam=movstr(numbuf,&tmpout[TMPNAM]);
 }
 
-Ldup(fa, fb)
+LOCAL VOID	Ldup(fa, fb)
 	REG INT		fa, fb;
 {
-	dup(fa|DUPFLG, fb);
+	dup2(fa, fb);
 	close(fa);
-	ioctl(fb, FIOCLEX, 0);
+	fcntl(fb, F_SETFD, FD_CLOEXEC);
 }
