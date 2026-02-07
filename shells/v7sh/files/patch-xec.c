diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ xec.c.orig xec.c
--- xec.c.orig	Fri Jun  4 02:51:03 2004
+++ xec.c	Sat Jun 19 18:42:25 2004
@@ -12,29 +12,36 @@
 
 LOCAL INT	parent;
 
-SYSTAB		commands;
-
+INT		ioset;
+STRING		pcsadr;
+INT		loopcnt;
+INT		breakcnt;
+BOOL		execbrk;
 
 
 /* ========	command execution	========*/
 
 
-execute(argt, execflg, pf1, pf2)
+INT	execute(argt, execflg, pf1, pf2)
 	TREPTR		argt;
+	INT		execflg;
 	INT		*pf1, *pf2;
 {
 	/* `stakbot' is preserved by this routine */
 	REG TREPTR	t;
 	STKPTR		sav=savstak();
+#if defined(SYSIII)
+	INT		bltflg=0;
+#endif
 
 	sigchk();
 
 	IF (t=argt) ANDF execbrk==0
 	THEN	REG INT		treeflgs;
 		INT		oldexit, type;
-		REG STRING	*com;
+		REG STRING	*com=NIL;	/* GCC */
 
-		treeflgs = t->tretyp; type = treeflgs&COMMSK;
+		treeflgs = t->treio.tretyp; type = treeflgs&COMMSK;
 		oldexit=exitval; exitval=0;
 
 		SWITCH type IN
@@ -42,16 +49,20 @@
 		case TCOM:
 			BEGIN
 			STRING		a1;
-			INT		argn, internal;
+			INT		argn, internal=0; /* GCC */
 			ARGPTR		schain=gchain;
-			IOPTR		io=t->treio;
+			IOPTR		io=t->treio.treio;
 			gchain=0;
-			argn = getarg(t);
+			argn = getarg((COMPTR) t);
 			com=scan(argn);
 			a1=com[1]; gchain=schain;
 
+#ifdef RENO
+			IF argn==0 ORF (internal=syslook(com[0],commands))
+#else /* V7 */
 			IF (internal=syslook(com[0],commands)) ORF argn==0
-			THEN	setlist(t->comset, 0);
+#endif
+			THEN	setlist(t->comnod.comset, 0);
 			FI
 
 			IF argn ANDF (flags&noexec)==0
@@ -71,44 +82,77 @@
 	
 						IF (f=pathopen(getpath(a1), a1)) < 0
 						THEN failed(a1,notfound);
+							/*NOTREACHED*/
 						ELSE execexp(0,f);
 						FI
 					FI
 					break;
 	
 				case SYSTIMES:
-					{
-					L_INT	t[4]; times(t);
-					prt(t[2]); blank(); prt(t[3]); newline();
-					}
+					BEGIN
+					TIMEBUF	timeb; times(&timeb);
+					prt(((CLOCK *)&timeb)[2]); blank();
+					prt(((CLOCK *)&timeb)[3]); newline();
+					END
 					break;
 	
 				case SYSEXIT:
+#if defined(SYSIII)
+					flags |= forked;	/* force exit */
+#endif
 					exitsh(a1?stoi(a1):oldexit);
+					/*NOTREACHED*/
 	
 				case SYSNULL:
 					io=0;
 					break;
 	
 				case SYSCONT:
+#if defined(ULTRIX)
+					IF loopcnt
+					THEN	execbrk = breakcnt = 1;
+						IF a1
+						THEN breakcnt = stoi(a1) FI
+						breakcnt = breakcnt > loopcnt ?
+						loopcnt : -breakcnt;
+					FI
+					break;
+#elif defined(SYSIII)
+					IF (execbrk=-loopcnt)!=0 ANDF a1
+					THEN breakcnt=stoi(a1);
+					FI
+					break;
+#else /* V7 */
 					execbrk = -loopcnt; break;
+#endif
 	
 				case SYSBREAK:
-					IF (execbrk=loopcnt) ANDF a1
+#if defined(ULTRIX)
+					IF loopcnt
+					THEN	execbrk = breakcnt = 1;
+						IF a1
+						THEN breakcnt = stoi(a1) FI
+						IF breakcnt > loopcnt
+						THEN breakcnt = loopcnt FI
+					FI
+#else /* V7 */
+					IF (execbrk=loopcnt)!=0 ANDF a1 /*GCC*/
 					THEN breakcnt=stoi(a1);
 					FI
+#endif
 					break;
 	
 				case SYSTRAP:
 					IF a1
 					THEN	BOOL	clear;
-						IF (clear=digit(*a1))==0
+						IF (clear=digit((INT) *a1))==0
 						THEN	++com;
 						FI
 						WHILE *++com
 						DO INT	i;
 						   IF (i=stoi(*com))>=MAXTRAP ORF i<MINTRAP
 						   THEN	failed(*com,badtrap);
+							/*NOTREACHED*/
 						   ELIF clear
 						   THEN	clrsig(i);
 						   ELSE	replace(&trapcom[i],a1);
@@ -133,41 +177,67 @@
 					com++;
 					initio(io); ioset=0; io=0;
 					IF a1==0 THEN break FI
+					/*FALLTHROUGH*/
 	
 				case SYSLOGIN:
+#if !defined(SYSIII)
 					flags |= forked;
+#endif
 					oldsigs(); execa(com); done();
-	
+					/*NOTREACHED*/
+#if defined(SYSIII)
+				case SYSNEWGRP:
+					IF flags&rshflg
+					THEN	failed(com[0],restricted);
+						/*NOTREACHED*/
+					ELSE	/* force bad exec to terminate shell */
+						flags |= forked;
+						oldsigs(); execa(com); done();
+						/*NOTREACHED*/
+					FI
+#endif
 				case SYSCD:
 					IF flags&rshflg
 					THEN	failed(com[0],restricted);
+						/*NOTREACHED*/
+#if defined(SYSIII)
+					ELIF	(argn >2)
+					THEN	failed(com[0],argcount);
+						/*NOTREACHED*/
+#endif
 					ELIF (a1==0 ANDF (a1=homenod.namval)==0) ORF chdir(a1)<0
 					THEN	failed(a1,baddir);
+						/*NOTREACHED*/
 					FI
 					break;
 	
 				case SYSSHFT:
 					IF dolc<1
 					THEN	error(badshift);
+						/*NOTREACHED*/
 					ELSE	dolv++; dolc--;
 					FI
 					assnum(&dolladr, dolc);
 					break;
 	
 				case SYSWAIT:
+#if defined(SYSIII)
+					await(a1?stoi(a1):-1,1);
+#else /* V7 */
 					await(-1);
+#endif
 					break;
 	
 				case SYSREAD:
+#if defined(SYSIII)
+					rwait=1;
+#endif
 					exitval=readvar(&com[1]);
+#if defined(SYSIII)
+					rwait=0;
+#endif
 					break;
 
-/*
-				case SYSTST:
-					exitval=testcmd(com);
-					break;
-*/
-
 				case SYSSET:
 					IF a1
 					THEN	INT	argc;
@@ -175,7 +245,7 @@
 						IF argc>1
 						THEN	setargs(com+argn-argc);
 						FI
-					ELIF t->comset==0
+					ELIF ((COMPTR) t)->comset==0
 					THEN	/*scan name chain and print*/
 						namscan(printnam);
 					FI
@@ -183,6 +253,8 @@
 	
 				case SYSRDONLY:
 					exitval=N_RDONLY;
+					/*FALLTHROUGH*/
+
 				case SYSXPORT:
 					IF exitval==0 THEN exitval=N_EXPORT; FI
 	
@@ -196,48 +268,120 @@
 	
 				case SYSEVAL:
 					IF a1
-					THEN	execexp(a1,&com[2]);
+					THEN	execexp(a1,(UFD) &com[2]);
 					FI
 					break;
-
+#if defined(ULTRIX)
+                                case SYSULIMIT:
+					BEGIN
+					LONG i = 0;
+					INT command = 2;
+
+					IF **++com == '-'
+					THEN	IF *(*com+1) != 'f'
+						THEN error(badopt) FI
+						com++;
+					FI
+					IF *com
+					THEN	WHILE **com >= '0' && **com <= '9'
+						DO	i *= 10;
+							i += **com - '0';
+							IF i < 0
+							THEN error(badulimit) FI
+							(*com)++;
+						OD
+						IF **com
+						THEN error(badulimit) FI
+					ELSE	command--;
+					FI
+					i = ulimit(command,i);
+					IF i < 0 THEN error(badulimit) FI
+					IF command == i
+					THEN prl(i); newline(); FI
+					END
+					break;
+#endif
                                 case SYSUMASK:
-                                        if (a1) {
-                                                int c, i
+					IF a1
+					THEN	INT c, i;
                                                 i = 0;
-                                                while ((c = *a1++) >= '0' &&
+						WHILE ((c = *a1++) >= '0' ANDF
                                                         c <= '7')
-                                                        i = (i << 3) + c - '0';
+						DO	i = (i << 3) + c - '0';
+						OD
                                                 umask(i);
-                                        } else {
-                                                int i, j;
+                                        ELSE	MODE i; INT j;
                                                 umask(i = umask(0));
                                                 prc('0');
-                                                for (j = 6; j >= 0; j -= 3)
-                                                        prc(((i>>j)&07) + '0');
+						FOR j = 6; j >= 0; j -= 3
+						DO	prc(((i>>j)&07) + '0');
+						OD
                                                 newline();
-                                        }
+                                        FI
                                         break;
 	
 				default:
+#if defined(SYSIII)
+					IF (internal=syslook(com[0],builtins))>0
+					THEN	builtin(internal, argn, com);
+						bltflg=1;
+					FI
+#else /* V7 */
 					internal=builtin(argn,com);
-	
+#endif
 				ENDSW
 
 				IF internal
+#if defined(SYSIII)
+				THEN	IF io ANDF !bltflg
+					THEN	error(illegal);
+						/*NOTREACHED*/
+					FI
+#else /* V7 */
 				THEN	IF io THEN error(illegal) FI
+#endif
 					chktrap();
 					break;
 				FI
-			ELIF t->treio==0
+			ELIF t->treio.treio==0
+#if defined(SYSIII)
+			THEN	chktrap();
+				break;
+#else /* V7 */
 			THEN	break;
+#endif
 			FI
 			END
+			/*FALLTHROUGH*/
 	
 		case TFORK:
 			IF execflg ANDF (treeflgs&(FAMP|FPOU))==0
 			THEN	parent=0;
+#if defined(SYSIII)
+			ELSE	UINT forkcnt=1;
+			/* FORKLIM is the max period between forks -
+			   power of 2 usually.  Currently shell tries
+			   after 2,4,8,16, and 32 seconds and then quits */
+				WHILE (parent=fork()) == -1
+				DO	IF (forkcnt=(forkcnt*2)) > FORKLIM /* 32 */
+					THEN	SWITCH errno IN
+						case ENOMEM:
+							error(noswap);
+							/*NOTREACHED*/
+							break;
+						default:
+						/* case EAGAIN: */
+							error(nofork);
+							/*NOTREACHED*/
+							break;
+						ENDSW
+					FI
+					sigchk(); alarm(forkcnt); pause();
+				OD
+#else /* V7 */
 			ELSE	WHILE (parent=fork()) == -1
 				DO sigchk(); alarm(10); pause() OD
+#endif
 			FI
 
 			IF parent
@@ -248,7 +392,11 @@
 				FI
 				IF treeflgs&FPCL THEN closepipe(pf1) FI
 				IF (treeflgs&(FAMP|FPOU))==0
+#if defined(SYSIII)
+				THEN	await(parent,0);
+#else /* V7 */
 				THEN	await(parent);
+#endif
 				ELIF (treeflgs&FAMP)==0
 				THEN	post(parent);
 				ELSE	assnum(&pcsadr, parent);
@@ -268,7 +416,8 @@
 				/* except for those `lost' by trap   */
 				oldsigs();
 				IF treeflgs&FINT
-				THEN	signal(INTR,1); signal(QUIT,1);
+				THEN	signal(INTR,SIG_IGN);
+					signal(QUIT,SIG_IGN);
 				FI
 
 				/* pipe in or out */
@@ -287,111 +436,203 @@
 				FI
 
 				/* io redirection */
-				initio(t->treio);
+				initio(t->treio.treio);
 				IF type!=TCOM
-				THEN	execute(t->forktre,1);
+				THEN	execute(t->forknod.forktre,1,0,0);
 				ELIF com[0]!=ENDARGS
-				THEN	setlist(t->comset,N_EXPORT);
+				THEN	setlist(t->comnod.comset,N_EXPORT);
 					execa(com);
 				FI
 				done();
+				/*NOTREACHED*/
 			FI
 
 		case TPAR:
 			rename(dup(2),output);
-			execute(t->partre,execflg);
+			execute(t->parnod.partre,execflg,0,0);
 			done();
+			/*NOTREACHED*/
 
 		case TFIL:
 			BEGIN
 			   INT pv[2]; chkpipe(pv);
-			   IF execute(t->lstlef, 0, pf1, pv)==0
-			   THEN	execute(t->lstrit, execflg, pv, pf2);
+			   IF execute(t->lstnod.lstlef, 0, pf1, pv)==0
+			   THEN	execute(t->lstnod.lstrit, execflg, pv, pf2);
 			   ELSE	closepipe(pv);
 			   FI
 			END
 			break;
 
 		case TLST:
-			execute(t->lstlef,0);
-			execute(t->lstrit,execflg);
+			execute(t->lstnod.lstlef,0,0,0);
+			execute(t->lstnod.lstrit,execflg,0,0);
 			break;
 
 		case TAND:
-			IF execute(t->lstlef,0)==0
-			THEN	execute(t->lstrit,execflg);
+			IF execute(t->lstnod.lstlef,0,0,0)==0
+			THEN	execute(t->lstnod.lstrit,execflg,0,0);
 			FI
 			break;
 
 		case TORF:
-			IF execute(t->lstlef,0)!=0
-			THEN	execute(t->lstrit,execflg);
+			IF execute(t->lstnod.lstlef,0,0,0)!=0
+			THEN	execute(t->lstnod.lstrit,execflg,0,0);
 			FI
 			break;
 
 		case TFOR:
+			/* for.. do */
 			BEGIN
-			   NAMPTR	n = lookup(t->fornam);
+			   NAMPTR	n = lookup(t->fornod.fornam);
 			   STRING	*args;
 			   DOLPTR	argsav=0;
 
-			   IF t->forlst==0
+			   IF t->fornod.forlst==0
 			   THEN    args=dolv+1;
 				   argsav=useargs();
 			   ELSE	   ARGPTR	schain=gchain;
 				   gchain=0;
-				   trim((args=scan(getarg(t->forlst)))[0]);
+				   trim((args=scan(getarg(t->fornod.forlst)))[0]);
 				   gchain=schain;
 			   FI
 			   loopcnt++;
+#if defined(SYSIII)
+			   WHILE *args!=ENDARGS ANDF execbrk<=0
+#else /* V7 */
 			   WHILE *args!=ENDARGS ANDF execbrk==0
+#endif
 			   DO	assign(n,*args++);
-				execute(t->fortre,0);
+				execute(t->fornod.fortre,0,0,0);
+#if defined(ULTRIX)
+				IF breakcnt < 0
+				THEN execbrk = (++breakcnt != 0) FI
+#elif defined(SYSIII)
+				IF execbrk
+				THEN	IF breakcnt > 1 ORF execbrk > 0
+					THEN	break;
+					ELSE	execbrk = breakcnt = 0;
+					FI
+				FI
+#else /* V7 */
 				IF execbrk<0 THEN execbrk=0 FI
+#endif
 			   OD
+#if defined(ULTRIX)
+			   IF breakcnt > 0
+			   THEN execbrk = (--breakcnt != 0) FI
+			   loopcnt--;
+#else /* V7 */
 			   IF breakcnt THEN breakcnt-- FI
+#if defined(SYSIII)
+			   execbrk = (execbrk < 0 ? -breakcnt : breakcnt);
+			   loopcnt--;
+#else /* V7 */
 			   execbrk=breakcnt; loopcnt--;
-			   argfor=freeargs(argsav);
+#endif
+#endif
+			   argfor=(DOLPTR) freeargs(argsav);
 			END
 			break;
 
 		case TWH:
+			/* while.. do */
 		case TUN:
+			/* do.. until */
 			BEGIN
 			   INT		i=0;
+#if defined(RENO)
+			   INT		saveflg;
 
+			   saveflg = flags&errflg;
+#endif
 			   loopcnt++;
-			   WHILE execbrk==0 ANDF (execute(t->whtre,0)==0)==(type==TWH)
-			   DO i=execute(t->dotre,0);
+#if defined(RENO)
+#if defined(SYSIII)
+			   WHILE execbrk<=0
+#else /* RENO */
+			   WHILE execbrk==0
+#endif
+			   DO	flags &= ~errflg;
+				i=execute(t->whnod.whtre,0,0,0);
+				flags |= saveflg;
+				IF (i==0)!=(type==TWH) THEN break FI
+				i=execute(t->whnod.dotre,0,0,0);
+#else /* V7 */
+			   WHILE execbrk==0 ANDF (execute(t->whnod.whtre,0,0,0)==0)==(type==TWH)
+			   DO (i=execute(t->whnod.dotre,0,0,0))!=0; /* GCC */
+#endif
+#if defined(ULTRIX)
+				IF breakcnt < 0
+				THEN execbrk = (++breakcnt != 0) FI
+#elif defined(SYSIII)
+				IF execbrk
+				THEN	IF breakcnt > 1 ORF execbrk > 0
+					THEN	break;
+					ELSE	execbrk = breakcnt = 0;
+					FI
+				FI
+#else /* V7 */
 			      IF execbrk<0 THEN execbrk=0 FI
+#endif
 			   OD
+#if defined(ULTRIX)
+			   IF breakcnt > 0
+			   THEN execbrk = (--breakcnt != 0) FI
+			   loopcnt--; exitval= i;
+#else /* V7 */
 			   IF breakcnt THEN breakcnt-- FI
+#if defined(SYSIII)
+			   execbrk = (execbrk < 0 ? -breakcnt : breakcnt);
+			   loopcnt--; exitval= i;
+#else /* V7 */
 			   execbrk=breakcnt; loopcnt--; exitval=i;
+#endif
+#endif
 			END
 			break;
 
 		case TIF:
-			IF execute(t->iftre,0)==0
-			THEN	execute(t->thtre,execflg);
-			ELSE	execute(t->eltre,execflg);
-			FI
+#if RENO
+			BEGIN
+				INT	i, saveflg;
+
+				saveflg = flags&errflg;
+				flags &= ~errflg;
+				i=execute(t->ifnod.iftre,0,0,0);
+				flags |= saveflg;
+				IF i==0
+#else /* V7 */
+				IF execute(t->ifnod.iftre,0,0,0)==0
+#endif
+				THEN	execute(t->ifnod.thtre,execflg,0,0);
+#if defined(SYSIII)
+				ELIF t->ifnod.eltre
+				THEN	execute(t->ifnod.eltre,execflg,0,0);
+				ELSE	exitval=0; /* force zero exit for if-then-fi */
+#else /* V7 */
+				ELSE	execute(t->ifnod.eltre,execflg,0,0);
+#endif
+				FI
+#if RENO
+			END
+#endif
 			break;
 
 		case TSW:
 			BEGIN
-			   REG STRING	r = mactrim(t->swarg);
-			   t=t->swlst;
-			   WHILE t
-			   DO	ARGPTR		rex=t->regptr;
+			   REG STRING	r = mactrim(t->swnod.swarg);
+			   REG REGPTR	eg = t->swnod.swlst;
+			   WHILE eg
+			   DO	ARGPTR	rex=eg->regptr;
 				WHILE rex
 				DO	REG STRING	s;
 					IF gmatch(r,s=macro(rex->argval)) ORF (trim(s), eq(r,s))
-					THEN	execute(t->regcom,0);
+					THEN	execute(eg->regcom,0,0,0);
 						t=0; break;
 					ELSE	rex=rex->argnxt;
 					FI
 				OD
-				IF t THEN t=t->regnxt FI
+				IF eg THEN eg=eg->regnxt FI
 			   OD
 			END
 			break;
@@ -405,17 +646,17 @@
 }
 
 
-execexp(s,f)
+VOID	execexp(s,f)
 	STRING		s;
 	UFD		f;
 {
 	FILEBLK		fb;
 	push(&fb);
 	IF s
-	THEN	estabf(s); fb.feval=f;
+	THEN	estabf(s); fb.feval=(STRING *)f;
 	ELIF f>=0
 	THEN	initf(f);
 	FI
-	execute(cmd(NL, NLFLG|MTFLG),0);
+	execute(cmd(NL, NLFLG|MTFLG),0,0,0);
 	pop();
 }
