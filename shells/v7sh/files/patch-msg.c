diff -u -x CVS -x work -x core -x *.core -x #* -x *~ -x *.orig -x *.rej -I $Id.*$ -I $.+BSD.*$ msg.c.orig msg.c
--- msg.c.orig	Fri Jun  4 02:51:02 2004
+++ msg.c	Sat Jun 19 18:42:23 2004
@@ -10,64 +10,88 @@
 
 #include	"defs.h"
 #include	"sym.h"
+#include	"pathnames.h"
 
-MSG		version = "\nVERSION sys137	DATE 1978 Nov 6 14:29:22\n";
+CMSG		version = "\nVERSION sys137	DATE 1978 Nov 6 14:29:22\n";
 
 /* error messages */
-MSG	badopt		= "bad option(s)";
-MSG	mailmsg		= "you have mail\n";
-MSG	nospace		= "no space";
-MSG	synmsg		= "syntax error";
-
-MSG	badnum		= "bad number";
-MSG	badparam	= "parameter not set";
-MSG	badsub		= "bad substitution";
-MSG	badcreate	= "cannot create";
-MSG	illegal		= "illegal io";
-MSG	restricted	= "restricted";
-MSG	piperr		= "cannot make pipe";
-MSG	badopen		= "cannot open";
-MSG	coredump	= " - core dumped";
-MSG	arglist		= "arg list too long";
-MSG	txtbsy		= "text busy";
-MSG	toobig		= "too big";
-MSG	badexec		= "cannot execute";
-MSG	notfound	= "not found";
-MSG	badfile		= "bad file number";
-MSG	badshift	= "cannot shift";
-MSG	baddir		= "bad directory";
-MSG	badtrap		= "bad trap";
-MSG	wtfailed	= "is read only";
-MSG	notid		= "is not an identifier";
+CMSG	badopt		= "bad option(s)";
+CMSG	mailmsg		= "you have mail\n";
+CMSG	nospace		= "no space";
+CMSG	synmsg		= "syntax error";
+
+CMSG	badnum		= "bad number";
+#if defined(SYSIII)
+CMSG	badparam	= "parameter null or not set";
+CMSG	unset		= "parameter not set";
+#else /* V7 */
+CMSG	badparam	= "parameter not set";
+#endif
+CMSG	badsub		= "bad substitution";
+CMSG	badcreate	= "cannot create";
+CMSG	illegal		= "illegal io";
+CMSG	restricted	= "restricted";
+#if defined(SYSIII)
+CMSG	nofork		= "cannot fork: too many processes";
+CMSG	noswap		= "cannot fork: no swap space";
+#endif
+CMSG	piperr		= "cannot make pipe";
+CMSG	badopen		= "cannot open";
+CMSG	coredump	= " - core dumped";
+CMSG	arglist		= "arg list too long";
+#if defined(SYSIII)
+CMSG	argcount	= "argument count";
+#endif
+CMSG	txtbsy		= "text busy";
+CMSG	toobig		= "too big";
+CMSG	badexec		= "cannot execute";
+CMSG	notfound	= "not found";
+CMSG	badfile		= "bad file number";
+CMSG	badshift	= "cannot shift";
+CMSG	baddir		= "bad directory";
+CMSG	badtrap		= "bad trap";
+CMSG	memfault	= "cannot trap 11";
+CMSG	wtfailed	= "is read only";
+CMSG	notid		= "is not an identifier";
+CMSG	badulimit	= "bad ulimit";
+
+#if defined(SYSIII)
+/*	messages for 'builtin' functions	*/
+CMSG	btest		= "test";
+CMSG	badop		= "unknown operator";
+#endif
 
 /* built in names */
-MSG	pathname	= "PATH";
-MSG	homename	= "HOME";
-MSG	mailname	= "MAIL";
-MSG	fngname		= "FILEMATCH";
-MSG	ifsname		= "IFS";
-MSG	ps1name		= "PS1";
-MSG	ps2name		= "PS2";
+CMSG	pathname	= "PATH";
+CMSG	homename	= "HOME";
+CMSG	mailname	= "MAIL";
+CMSG	fngname		= "FILEMATCH";
+CMSG	ifsname		= "IFS";
+CMSG	ps1name		= "PS1";
+CMSG	ps2name		= "PS2";
 
 /* string constants */
-MSG	nullstr		= "";
-MSG	sptbnl		= " \t\n";
-MSG	defpath		= ":/bin:/usr/bin";
-MSG	colon		= ": ";
-MSG	minus		= "-";
-MSG	endoffile	= "end of file";
-MSG	unexpected 	= " unexpected";
-MSG	atline		= " at line ";
-MSG	devnull		= "/dev/null";
-MSG	execpmsg	= "+ ";
-MSG	readmsg		= "> ";
-MSG	stdprompt	= "$ ";
-MSG	supprompt	= "# ";
-MSG	profile		= ".profile";
-
+CMSG	nullstr		= "";
+CMSG	sptbnl		= " \t\n";
+CMSG	defpath		= _PATH_DEFPATH;
+CMSG	colon		= ": ";
+CMSG	minus		= "-";
+CMSG	endoffile	= "end of file";
+CMSG	endofline	= "newline or ;";
+CMSG	unexpected 	= " unexpected";
+CMSG	atline		= " at line ";
+CMSG	devnull		= _PATH_DEVNULL;
+CMSG	execpmsg	= "+ ";
+CMSG	readmsg		= "> ";
+CMSG	stdprompt	= "$ ";
+CMSG	supprompt	= "# ";
+CMSG	profile		= _PATH_DOTPROFILE;
+#if defined(SYSIII)
+CMSG	sysprofile	= _PATH_ETCPROFILE;
+#endif
 
 /* tables */
-SYSTAB reserved {
+SYSTAB reserved={
 		{"in",		INSYM},
 		{"esac",	ESSYM},
 		{"case",	CASYM},
@@ -83,19 +107,19 @@
 		{"until",	UNSYM},
 		{ "{",		BRSYM},
 		{ "}",		KTSYM},
-		{0,	0},
+		{0,	0}
 };
 
-STRING	sysmsg[] {
+CSTRING	sysmsg[]={
 		0,
 		"Hangup",
 		0,	/* Interrupt */
 		"Quit",
 		"Illegal instruction",
 		"Trace/BPT trap",
-		"IOT trap",
+		"Abort trap",	/* IOT trap */
 		"EMT trap",
-		"Floating exception",
+		"Floating point exception",
 		"Killed",
 		"Bus error",
 		"Memory fault",
@@ -103,25 +127,49 @@
 		0,	/* Broken pipe */
 		"Alarm call",
 		"Terminated",
-		"Signal 16",
+		"Urgent I/O condition",
+		"Stopped",
+		"Stopped from terminal",
+		"Continued",
+		"Child exited",
+		"Stopped on terminal input",
+		"Stopped on terminal output",
+		"Asynchronous I/O",
+		"Cputime limit exceeded",
+		"Filesize limit exceeded",
+		"Virtual timer expired",
+		"Profiling timer expired",
+		"Window size changed",
+		"Information request",
+		"User defined signal 1",
+		"User defined signal 2",
+		"Thread interrupt"
 };
+#if defined(RENO)
+INT		num_sysmsg = (sizeof sysmsg / sizeof sysmsg[0]);
+#endif
+
+CMSG		export = "export";
+CMSG		readonly = "readonly";
 
-MSG		export = "export";
-MSG		readonly = "readonly";
-SYSTAB	commands {
+SYSTAB	commands={
 		{"cd",		SYSCD},
 		{"read",	SYSREAD},
-/*
-		{"[",		SYSTST},
-*/
 		{"set",		SYSSET},
 		{":",		SYSNULL},
 		{"trap",	SYSTRAP},
+#if defined(ULTRIX)
+		{"ulimit",	SYSULIMIT},
+#endif
 		{"login",	SYSLOGIN},
 		{"wait",	SYSWAIT},
 		{"eval",	SYSEVAL},
 		{".",		SYSDOT},
+#if defined(SYSIII)
+		{"newgrp",	SYSNEWGRP},
+#else /* V7 */
 		{"newgrp",	SYSLOGIN},
+#endif
 		{readonly,	SYSRDONLY},
 		{export,	SYSXPORT},
 		{"chdir",	SYSCD},
@@ -132,5 +180,13 @@
 		{"exec",	SYSEXEC},
 		{"times",	SYSTIMES},
 		{"umask",	SYSUMASK},
-		{0,	0},
+		{0,	0}
+};
+
+#if defined(SYSIII)
+SYSTAB	builtins={
+		{btest,		TEST},
+		{"[",		TEST},
+		{0,	0}
 };
+#endif
