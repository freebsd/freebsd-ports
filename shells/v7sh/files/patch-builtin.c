diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ builtin.c.orig builtin.c
--- builtin.c.orig	Fri Jun  4 02:51:01 2004
+++ builtin.c	Sat Jun 19 18:42:21 2004
@@ -1,2 +1,43 @@
-builtin()
-{return(0);}
+#include        "defs.h"
+
+#if defined(SYSIII)
+VOID	builtin(xbuiltin, argn, com)
+/*
+	builtin commands are those that Bourne did not intend
+	to be part of his shell.
+	Redirection of i/o, or rather the lack of it, is still a
+	problem..
+*/
+	INT	xbuiltin;
+	INT	argn;
+	STRING	com[];
+{
+	SWITCH xbuiltin IN
+	case TEST:      /* test expression */
+		exitval = test(argn,com);
+		break;
+	ENDSW
+}
+
+VOID	bfailed(s1, s2, s3) 
+	/*	fake diagnostics to continue to look like original
+		test(1) diagnostics
+	*/
+	CSTRING s1, s2, s3;
+{
+	prp(); prs(s1);
+	IF s2
+	THEN	prs(colon); prs(s2); prs(s3);
+	FI
+	newline(); exitsh(ERROR);
+	/*NOTREACHED*/
+}
+#else /* V7 */
+INT	builtin(argn, com)
+	INT	argn;
+	STRING	com[];
+{
+	argn=argn; com=com;			/* GCC */
+	return(0);
+}
+#endif
