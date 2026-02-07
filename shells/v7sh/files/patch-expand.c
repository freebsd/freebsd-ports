diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ expand.c.orig expand.c
--- expand.c.orig	Fri Jun  4 02:51:01 2004
+++ expand.c	Sat Jun 19 18:42:22 2004
@@ -8,10 +8,6 @@
  */
 
 #include	"defs.h"
-#include	<sys/types.h>
-#define DIRSIZ 15
-#include	<sys/stat.h>
-#include	<sys/dir.h>
 
 
 
@@ -24,52 +20,98 @@
  *
  */
 
-PROC VOID	addg();
+LOCAL VOID	addg(STRING, STRING, STRING);
+#if defined(SYSIII)
+LOCAL VOID	chgquot(STRING, INT);
+#endif
+
+ARGPTR		gchain;
 
 
 INT	expand(as,rflg)
 	STRING		as;
+	INT		rflg;
 {
-	INT		count, dirf;
+	INT		count;
+	DIR		*dirf;
 	BOOL		dir=0;
 	STRING		rescan = 0;
 	REG STRING	s, cs;
 	ARGPTR		schain = gchain;
-	struct direct	entry;
+	DIRPTR		dp;
 	STATBUF		statb;
+	CHAR		buf[2];
 
 	IF trapnote&SIGSET THEN return(0); FI
 
-	s=cs=as; entry.d_name[DIRSIZ-1]=0; /* to end the string */
+	s=cs=as;
 
 	/* check for meta chars */
 	BEGIN
+#if defined(SYSIII)
+#define open open_
+	   REG BOOL slash, open; slash=0;open=0;
+	   LOOP
+		SWITCH *cs++ IN
+		case 0:		IF rflg ANDF slash THEN break;
+				ELSE return(0);
+				FI
+		case '/':	slash++;
+				open = 0;
+				continue;
+		case '[':	open++;
+				continue;
+		case ']':	IF open THEN break FI
+				continue;
+		case '?':
+		case '*':	cs--;
+				break;
+		default:	continue;
+		ENDSW
+		break;
+	   POOL
+#undef open
+#else /* V7 */
 	   REG BOOL slash; slash=0;
-	   WHILE !fngchar(*cs)
+	   WHILE !fngchar((INT) *cs)
 	   DO	IF *cs++==0
 		THEN	IF rflg ANDF slash THEN break; ELSE return(0) FI
 		ELIF *cs=='/'
 		THEN	slash++;
 		FI
 	   OD
+#endif
 	END
 
 	LOOP	IF cs==s
-		THEN	s=nullstr;
+		THEN	movstr(nullstr,s=buf);
 			break;
 		ELIF *--cs == '/'
 		THEN	*cs=0;
-			IF s==cs THEN s="/" FI
+			IF s==cs THEN movstr("/",s=buf) FI
 			break;
 		FI
 	POOL
+#if defined(SYSIII)
+	chgquot(s, 0);
+	IF stat(*s?s:".",&statb)>=0
+#else /* V7 */
 	IF stat(s,&statb)>=0
+#endif
 	    ANDF (statb.st_mode&S_IFMT)==S_IFDIR
-	    ANDF (dirf=open(s,0))>0
+#if defined(SYSIII)
+	    ANDF (dirf=opendir(*s?s:".")) != NULL
+#else /* V7 */
+	    ANDF (dirf=opendir(s)) != NULL
+#endif
 	THEN	dir++;
+	ELSE	dirf=NULL;
 	FI
+#if defined(SYSIII)
+	chgquot(s, 1);
+#endif
 	count=0;
-	IF *cs==0 THEN *cs++=0200 FI
+	IF *cs==0 THEN *cs++=QUOTE FI
 	IF dir
 	THEN	/* check for rescan */
 		REG STRING rs; rs=cs;
@@ -77,16 +119,33 @@
 		REP	IF *rs=='/' THEN rescan=rs; *rs=0; gchain=0 FI
 		PER	*rs++ DONE
 
-		WHILE read(dirf, &entry, 16) == 16 ANDF (trapnote&SIGSET) == 0
-		DO	IF entry.d_ino==0 ORF
-			    (*entry.d_name=='.' ANDF *cs!='.')
+#if defined(RENO)
+		IF setjmp(INTbuf) == 0 THEN trapjmp[INTR] = 1; FI
+		WHILE (trapnote&SIGSET) == 0 ANDF (dp = readdir(dirf)) != NULL
+#else /* V7 */
+		WHILE (dp = readdir(dirf)) != NULL ANDF (trapnote&SIGSET) == 0
+#endif
+		DO	IF (*dp->d_name=='.' ANDF *cs!='.')
 			THEN	continue;
 			FI
-			IF gmatch(entry.d_name, cs)
-			THEN	addg(s,entry.d_name,rescan); count++;
+#if defined(SYSIII)
+/*
+ *	Here lies the fix for the "echo * ^H/." problem when
+ *	there are files with metacharacters in there names.
+ */
+			chgquot(dp->d_name, 1);
+#endif
+			IF gmatch(dp->d_name, cs)
+			THEN	addg(s,dp->d_name,rescan); count++;
 			FI
+#if defined(SYSIII)
+			chgquot(dp->d_name, 0);
+#endif
 		OD
-		close(dirf);
+		closedir(dirf);
+#if defined(RENO)
+		trapjmp[INTR] = 0;
+#endif
 
 		IF rescan
 		THEN	REG ARGPTR	rchain;
@@ -103,43 +162,68 @@
 	FI
 
 	BEGIN
-	   REG CHAR	c;
+	   REG INT	c;
 	   s=as;
-	   WHILE c = *s
+	   WHILE (c = *s)!=0			/* GCC */
 	   DO	*s++=(c&STRIP?c:'/') OD
 	END
 	return(count);
 }
 
-gmatch(s, p)
+INT	gmatch(s, p)
 	REG STRING	s, p;
 {
 	REG INT		scc;
-	CHAR		c;
+	INT		c;
 
-	IF scc = *s++
+	IF (scc = *s++)!=0			/* GCC */
 	THEN	IF (scc &= STRIP)==0
-		THEN	scc=0200;
+		THEN	scc=QUOTE;
 		FI
 	FI
 	SWITCH c = *p++ IN
 
 	    case '[':
-		{BOOL ok; INT lc;
+		BEGIN
+		BOOL ok; INT lc;
+#if defined(SYSIII)
+		INT notflag=0;
+#endif
 		ok=0; lc=077777;
-		WHILE c = *p++
+#if defined(SYSIII)
+		IF *p == '!' ORF *p == '^' THEN notflag=1; p++; FI
+#endif
+		WHILE (c = *p++)!=0		/* GCC */
 		DO	IF c==']'
 			THEN	return(ok?gmatch(s,p):0);
 			ELIF c==MINUS
+#if defined(SYSIII)
+			THEN	IF notflag
+				THEN	IF lc>scc ORF scc>*(p++)
+					THEN ok++;
+					ELSE return(0)
+					FI
+				ELSE IF lc<=scc ANDF scc<=(*p++) THEN ok++ FI
+				FI
+			ELSE	IF notflag
+				THEN	IF scc!=(lc=(c&STRIP))
+					THEN ok++;
+					ELSE return(0)
+					FI
+				ELSE	IF scc==(lc=(c&STRIP)) THEN ok++ FI
+				FI
+#else /* V7 */
 			THEN	IF lc<=scc ANDF scc<=(*p++) THEN ok++ FI
 			ELSE	IF scc==(lc=(c&STRIP)) THEN ok++ FI
+#endif
 			FI
 		OD
 		return(0);
-		}
+		END
 
 	    default:
 		IF (c&STRIP)!=scc THEN return(0) FI
+		/*FALLTHROUGH*/
 
 	    case '?':
 		return(scc?gmatch(s,p):0);
@@ -165,7 +249,7 @@
 	s2 = locstak()+BYTESPERWORD;
 
 	s1=as1;
-	WHILE c = *s1++
+	WHILE (c = *s1++)!=0			/* GCC */
 	DO	IF (c &= STRIP)==0
 		THEN	*s2++='/';
 			break;
@@ -173,18 +257,42 @@
 		*s2++=c;
 	OD
 	s1=as2;
-	WHILE *s2 = *s1++ DO s2++ OD
-	IF s1=as3
+	WHILE (*s2 = *s1++)!=0 DO s2++ OD	/* GCC */
+	IF (s1=as3)!=NIL			/* GCC */
 	THEN	*s2++='/';
-		WHILE *s2++ = *++s1 DONE
+		WHILE (*s2++ = *++s1)!=0 DONE	/* GCC */
 	FI
-	makearg(endstak(s2));
+	makearg((ARGPTR) endstak(s2));
 }
 
-makearg(args)
-	REG STRING	args;
+VOID	makearg(args)
+	REG ARGPTR	args;
 {
 	args->argnxt=gchain;
-	gchain=args;
+	gchain=(ARGPTR) args;
 }
 
+#if defined(SYSIII)
+LOCAL VOID	chgquot(str, flg)
+	REG STRING	str;
+	REG INT		flg;
+{
+	REG INT i;
+ 
+	FOR i=0;str[i];i++
+	DO
+		SWITCH str[i] IN
+		case '*':
+		case '?':
+		case '[':
+		case '*'|QUOTE:
+		case '?'|QUOTE:
+		case '['|QUOTE:
+			IF flg==0
+			THEN	str[i] &= (~QUOTE);
+			ELSE	str[i] |= QUOTE;
+			FI
+		ENDSW
+	OD
+}
+#endif
