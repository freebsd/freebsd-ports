diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ defs.h.orig defs.h
--- defs.h.orig	Tue Jun 22 01:43:19 2004
+++ defs.h	Tue Jun 22 01:55:49 2004
@@ -1,8 +1,32 @@
 #
 /*
  *	UNIX shell
+ *
+ *	S. R. Bourne
+ *	Bell Telephone Laboratories
+ *
  */
 
+#include	<sys/types.h>
+#include	<sys/stat.h>
+#include	<sys/times.h>
+#include	<sys/wait.h>
+#include	<dirent.h>
+#include	<errno.h>
+#include	<fcntl.h>
+#include	<setjmp.h>
+#include	<signal.h>
+#include	<stdlib.h>
+#include	<string.h>
+#if defined(ULTRIX)
+#if (__FreeBSD_version - 0) >= 500005
+#include	<ulimit.h>
+#else
+#include	"ulimit.h"
+#endif
+#endif
+#include	<unistd.h>
+
 /* error exits from various parts of shell */
 #define ERROR	1
 #define SYNBAD	2
@@ -51,11 +75,22 @@
 #define SYSNULL 16
 #define SYSREAD 17
 #define SYSTST	18
-#define	SYSUMASK	19
+#define	SYSUMASK 19
+#if defined(SYSIII)
+#define SYSNEWGRP 20
+#endif
+#if defined(ULTRIX)
+#define SYSULIMIT 21
+#endif
+
+#if defined(SYSIII)
+/*	builtin table	*/
+#define TEST	127
+#endif
 
 /* used for input and output of shell */
-#define INIO 10
-#define OTIO 11
+#define INIO	18	/* V7 - 10 */
+#define OTIO	19	/* V7 - 11 */
 
 /*io nodes*/
 #define USERIO	10
@@ -77,35 +112,145 @@
 
 
 /* result type declarations */
-#define alloc malloc
-ADDRESS		alloc();
-VOID		addblok();
-STRING		make();
-STRING		movstr();
-TREPTR		cmd();
-TREPTR		makefork();
-NAMPTR		lookup();
-VOID		setname();
-VOID		setargs();
-DOLPTR		useargs();
-REAL		expr();
-STRING		catpath();
-STRING		getpath();
-STRING		*scan();
-STRING		mactrim();
-STRING		macro();
-STRING		execs();
-VOID		await();
-VOID		post();
-STRING		copyto();
-VOID		exname();
-STRING		staknam();
-VOID		printnam();
-VOID		printflg();
-VOID		prs();
-VOID		prc();
-VOID		getenv();
-STRING		*setenv();
+/* args.c */
+PROC INT	options(INT, STRING *);
+PROC VOID	setargs(STRING *);
+PROC DOLPTR	freeargs(DOLPTR);
+PROC VOID	clearup(VOID);
+PROC DOLPTR	useargs(VOID);
+/* blok.c */
+PROC ADDRESS	alloc(POS);
+PROC VOID	addblok(POS);
+#define free	free_
+PROC VOID	free(BLKPTR);
+/* builtin.c */
+#if defined(SYSIII)
+PROC VOID	builtin(INT, INT, STRING *);
+#else /* V7 */
+PROC INT	builtin(INT, STRING *);
+#endif
+PROC VOID	bfailed(CSTRING, CSTRING, CSTRING);
+/* cmd.c */
+PROC TREPTR	makefork(INT, TREPTR);
+PROC TREPTR	cmd(INT, INT);
+/* error.c */
+PROC VOID	exitset(VOID);
+PROC VOID	sigchk(VOID);
+PROC VOID	failed(CSTRING, CSTRING);
+PROC VOID	error(CSTRING);
+PROC VOID	exitsh(INT);
+PROC VOID	done(VOID);
+PROC VOID	rmtemp(IOPTR);
+/* expand.c */
+PROC INT	expand(STRING, INT);
+PROC INT	gmatch(STRING, STRING);
+PROC VOID	makearg(ARGPTR);
+/* expr.c */
+/* PROC REAL	expr(); */
+/* fault.c */
+PROC VOID	fault(INT);
+PROC VOID	stdsigs(VOID);
+PROC SIGPTR	ignsig(INT);
+PROC VOID	getsig(INT);
+PROC VOID	oldsigs(VOID);
+PROC VOID	clrsig(INT);
+PROC VOID	chktrap(VOID);
+/* io.c */
+PROC VOID	initf(UFD);
+PROC INT	estabf(STRING);
+PROC VOID	push(FILEPTR);
+PROC INT	pop(VOID);
+PROC VOID	chkpipe(INT *);
+PROC INT	chkopen(CSTRING);
+#define rename	rename_
+PROC VOID	rename(INT, INT);
+PROC INT	create(STRING);
+PROC INT	tmpfil(VOID);
+PROC VOID	copy(IOPTR);
+/* macro.c */
+PROC STRING	macro(STRING);
+PROC VOID	subst(INT, INT);
+/* main.c */
+PROC VOID	chkpr(INT);
+PROC VOID	settmp(VOID);
+/* name.c */
+PROC INT	syslook(STRING, SYSTAB);
+PROC VOID	setlist(ARGPTR, INT);
+#if defined(SYSIII)
+PROC INT	setname(STRING, INT);
+#else /* V7 */
+PROC VOID	setname(STRING, INT);
+#endif
+PROC VOID	replace(STRING *, CSTRING);
+PROC VOID	dfault(NAMPTR, CSTRING);
+PROC VOID	assign(NAMPTR, CSTRING);
+PROC INT	readvar(STRING *);
+PROC VOID	assnum(STRING *, INT);
+PROC STRING	make(CSTRING);
+PROC NAMPTR	lookup(CSTRING);
+PROC VOID	namscan(VOID(*)(NAMPTR));
+PROC VOID	printnam(NAMPTR);
+PROC VOID	exname(NAMPTR);
+PROC VOID	printflg(NAMPTR);
+#define getenv getenv_
+#if defined(SYSIII)
+PROC INT	getenv(VOID);
+#else /* V7 */
+PROC VOID	getenv(VOID);
+#endif
+#define setenv setenv_
+PROC STRING	*setenv(VOID);
+/* print.c */
+PROC VOID	newline(VOID);
+PROC VOID	blank(VOID);
+PROC VOID	prp(VOID);
+PROC VOID	prs(CSTRING);
+PROC VOID	prc(INT);
+PROC VOID	prt(CLOCK);
+PROC VOID	prn(INT);
+PROC VOID	prl(LONG);
+PROC VOID	itos(INT);
+PROC VOID	ltos(LONG);
+PROC INT	stoi(CSTRING);
+/* service.c */
+PROC VOID	initio(IOPTR);
+#if defined(SYSIII)
+PROC CSTRING	simple(CSTRING);
+#endif
+PROC CSTRING	getpath(CSTRING);
+PROC INT	pathopen(CSTRING, CSTRING);
+PROC CSTRING	catpath(CSTRING, CSTRING);
+PROC VOID	execa(STRING *);
+PROC VOID	postclr(VOID);
+PROC VOID	post(INT);
+#if defined(SYSIII)
+PROC VOID	await(INT, INT);
+#else /* V7 */
+PROC VOID	await(INT);
+#endif
+PROC VOID	trim(STRING);
+PROC STRING	mactrim(STRING);
+PROC STRING	*scan(INT);
+PROC INT	getarg(COMPTR);
+/* setbrk.c */
+PROC BYTPTR	setbrk(INT);
+/* stak.c -> stak.h */
+/* string.c */
+PROC STRING	movstr(CSTRING, STRING);
+PROC INT	any(INT, CSTRING);
+PROC INT	cf(CSTRING, CSTRING);
+PROC INT	length(CSTRING);
+/* test.c */
+#if defined(SYSIII)
+PROC INT	test(INT, STRING *);
+#endif
+/* word.c */
+PROC INT	word(VOID);
+PROC INT	nextc(INT);
+PROC INT	readc(VOID);
+/* xec.c */
+PROC INT	execute(TREPTR, INT, INT *, INT *);
+PROC VOID	execexp(STRING, UFD);
 
 #define attrib(n,f)	(n->namflg |= f)
 #define round(a,b)	(((int)((ADR(a)+b)-1))&~((b)-1))
@@ -115,16 +260,20 @@
 #define assert(x)	;
 
 /* temp files and io */
-UFD		output;
-INT		ioset;
-IOPTR		iotemp;		/* files to be deleted sometime */
-IOPTR		iopend;		/* documents waiting to be read at NL */
+EXTERN UFD	output;
+EXTERN INT	ioset;
+EXTERN IOPTR	iotemp;		/* files to be deleted sometime */
+EXTERN IOPTR	iopend;		/* documents waiting to be read at NL */
+#if defined(SYSIII)
+EXTERN INT	stripflg;
+#endif
+EXTERN BOOL	nosubst;
 
 /* substitution */
-INT		dolc;
-STRING		*dolv;
-DOLPTR		argfor;
-ARGPTR		gchain;
+EXTERN INT	dolc;
+EXTERN STRING	*dolv;
+EXTERN DOLPTR	argfor;
+EXTERN ARGPTR	gchain;
 
 /* stack */
 #define		BLK(x)	((BLKPTR)(x))
@@ -136,68 +285,77 @@
 #include	"stak.h"
 
 /* string constants */
-MSG		atline;
-MSG		readmsg;
-MSG		colon;
-MSG		minus;
-MSG		nullstr;
-MSG		sptbnl;
-MSG		unexpected;
-MSG		endoffile;
-MSG		synmsg;
+EXTERN CMSG	atline;
+EXTERN CMSG	readmsg;
+EXTERN CMSG	colon;
+EXTERN CMSG	minus;
+EXTERN CMSG	nullstr;
+EXTERN CMSG	sptbnl;
+EXTERN CMSG	unexpected;
+EXTERN CMSG	endoffile;
+EXTERN CMSG	endofline;
+EXTERN CMSG	synmsg;
 
 /* name tree and words */
-SYSTAB		reserved;
-INT		wdval;
-INT		wdnum;
-ARGPTR		wdarg;
-INT		wdset;
-BOOL		reserv;
+EXTERN SYSTAB	reserved;
+EXTERN SYSTAB	commands;
+#if defined(SYSIII)
+EXTERN SYSTAB	builtins;
+#endif
+EXTERN INT	wdval;
+EXTERN INT	wdnum;
+EXTERN ARGPTR	wdarg;
+EXTERN INT	wdset;
+EXTERN BOOL	reserv;
 
 /* prompting */
-MSG		stdprompt;
-MSG		supprompt;
-MSG		profile;
+EXTERN CMSG	stdprompt;
+EXTERN CMSG	supprompt;
+EXTERN CMSG	profile;
+#if defined(SYSIII)
+EXTERN CMSG	sysprofile;
+#endif
 
 /* built in names */
-NAMNOD		fngnod;
-NAMNOD		ifsnod;
-NAMNOD		homenod;
-NAMNOD		mailnod;
-NAMNOD		pathnod;
-NAMNOD		ps1nod;
-NAMNOD		ps2nod;
+EXTERN NAMNOD	fngnod;
+EXTERN NAMNOD	ifsnod;
+EXTERN NAMNOD	homenod;
+EXTERN NAMNOD	mailnod;
+EXTERN NAMNOD	pathnod;
+EXTERN NAMNOD	ps1nod;
+EXTERN NAMNOD	ps2nod;
 
 /* special names */
-MSG		flagadr;
-STRING		cmdadr;
-STRING		exitadr;
-STRING		dolladr;
-STRING		pcsadr;
-STRING		pidadr;
+EXTERN MSG	flagadr;
+EXTERN STRING	cmdadr;
+EXTERN STRING	exitadr;
+EXTERN STRING	dolladr;
+EXTERN STRING	pcsadr;
+EXTERN STRING	pidadr;
 
-MSG		defpath;
+EXTERN CMSG	defpath;
 
 /* names always present */
-MSG		mailname;
-MSG		homename;
-MSG		pathname;
-MSG		fngname;
-MSG		ifsname;
-MSG		ps1name;
-MSG		ps2name;
+EXTERN CMSG	mailname;
+EXTERN CMSG	homename;
+EXTERN CMSG	pathname;
+EXTERN CMSG	fngname;
+EXTERN CMSG	ifsname;
+EXTERN CMSG	ps1name;
+EXTERN CMSG	ps2name;
 
 /* transput */
-CHAR		tmpout[];
-STRING		tmpnam;
-INT		serial;
+EXTERN CHAR	tmpout[];
+#define tmpnam	tmpnam_
+EXTERN STRING	tmpnam;
+EXTERN INT	serial;
 #define		TMPNAM 7
-FILE		standin;
+EXTERN FILEPTR	standin;
 #define input	(standin->fdes)
 #define eof	(standin->feof)
-INT		peekc;
-STRING		comdiv;
-MSG		devnull;
+EXTERN INT	peekc;
+EXTERN STRING	comdiv;
+EXTERN CMSG	devnull;
 
 /* flags */
 #define		noexec	01
@@ -211,77 +369,122 @@
 #define		rshflg	0400
 #define		waiting	01000
 #define		stdflg	02000
+#define		STDFLG	's'
+#define		STDFLGLOC 4
 #define		execpr	04000
 #define		readpr	010000
 #define		keyflg	020000
-INT		flags;
+EXTERN INT	flags;
+#if defined(SYSIII)
+EXTERN BOOL	rwait;
+EXTERN BOOL	wasintr;	/*	used to tell if break or delete is hit
+					while executing a wait	*/
+#endif
 
 /* error exits from various parts of shell */
-#include	<setjmp.h>
-jmp_buf		subshell;
-jmp_buf		errshell;
+EXTERN jmp_buf	subshell;
+EXTERN jmp_buf	errshell;
+#if defined(RENO)
+EXTERN jmp_buf	INTbuf;
+#endif
 
 /* fault handling */
 #include	"brkincr.h"
-POS		brkincr;
+EXTERN INT	brkincr;
 
 #define MINTRAP	0
-#define MAXTRAP	17
+#define MAXTRAP	33
 
-#define INTR	2
-#define QUIT	3
-#define MEMF	11
-#define ALARM	14
-#define KILL	15
+#define INTR	SIGINT
+#define QUIT	SIGQUIT
+#define MEMF	SIGSEGV
+#define ALARM	SIGALRM
+#define KILL	SIGTERM
 #define TRAPSET	2
 #define SIGSET	4
 #define SIGMOD	8
-
-VOID		fault();
-BOOL		trapnote;
-STRING		trapcom[];
-BOOL		trapflg[];
+#if defined(SYSIII)
+#define SIGCAUGHT 16
+#endif
+
+EXTERN BOOL	trapnote;
+EXTERN STRING	trapcom[];
+EXTERN BOOL	trapflg[];
+#if defined(RENO)
+EXTERN BOOL	trapjmp[];
+#endif
 
 /* name tree and words */
-STRING		*environ;
-CHAR		numbuf[];
-MSG		export;
-MSG		readonly;
+EXTERN STRING	*environ;
+EXTERN CHAR	numbuf[];
+EXTERN CMSG	export;
+EXTERN CMSG	readonly;
 
 /* execflgs */
-INT		exitval;
-BOOL		execbrk;
-INT		loopcnt;
-INT		breakcnt;
+EXTERN INT	exitval;
+EXTERN BOOL	execbrk;
+EXTERN INT	loopcnt;
+EXTERN INT	breakcnt;
 
 /* messages */
-MSG		mailmsg;
-MSG		coredump;
-MSG		badopt;
-MSG		badparam;
-MSG		badsub;
-MSG		nospace;
-MSG		notfound;
-MSG		badtrap;
-MSG		baddir;
-MSG		badshift;
-MSG		illegal;
-MSG		restricted;
-MSG		execpmsg;
-MSG		notid;
-MSG		wtfailed;
-MSG		badcreate;
-MSG		piperr;
-MSG		badopen;
-MSG		badnum;
-MSG		arglist;
-MSG		txtbsy;
-MSG		toobig;
-MSG		badexec;
-MSG		notfound;
-MSG		badfile;
+EXTERN CMSG	mailmsg;
+EXTERN CMSG	coredump;
+EXTERN CMSG	badopt;
+EXTERN CMSG	badparam;
+#if defined(SYSIII)
+EXTERN CMSG	unset;
+#endif
+EXTERN CMSG	badsub;
+EXTERN CMSG	nospace;
+EXTERN CMSG	badtrap;
+EXTERN CMSG	memfault;
+EXTERN CMSG	baddir;
+EXTERN CMSG	badshift;
+EXTERN CMSG	illegal;
+EXTERN CMSG	restricted;
+EXTERN CMSG	execpmsg;
+EXTERN CMSG	notid;
+EXTERN CMSG	badulimit;
+EXTERN CMSG	wtfailed;
+EXTERN CMSG	badcreate;
+#if defined(SYSIII)
+EXTERN CMSG	nofork;
+EXTERN CMSG	noswap;
+#endif
+EXTERN CMSG	piperr;
+EXTERN CMSG	badopen;
+EXTERN CMSG	badnum;
+EXTERN CMSG	arglist;
+#if defined(SYSIII)
+EXTERN CMSG	argcount;
+#endif
+EXTERN CMSG	txtbsy;
+EXTERN CMSG	toobig;
+EXTERN CMSG	badexec;
+EXTERN CMSG	notfound;
+EXTERN CMSG	badfile;
+EXTERN CSTRING	sysmsg[];
+#if defined(RENO)
+EXTERN INT	num_sysmsg;
+#endif
+
+#if defined(SYSIII)
+/*	'builtin' error messages	*/
+EXTERN CMSG	btest;
+EXTERN CMSG	badop;
+#endif
+
+#if defined(SYSIII)
+/*	fork constant	*/
+#define FORKLIM	32
+#endif
+
+#if defined(SYSIII) || defined(RENO)
+/*	comment delimeter	*/
+#define COMCHAR	'#'
+#endif
 
-address	end[];
+EXTERN address	end[];
 
 #include	"ctype.h"
 
