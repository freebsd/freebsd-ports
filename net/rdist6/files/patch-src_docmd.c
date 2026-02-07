--- src/docmd.c.orig	1998-11-10 04:08:32 UTC
+++ src/docmd.c
@@ -102,7 +102,8 @@ static void notify(rhost, to, lmod)
 	register struct namelist *to;
 	time_t lmod;
 {
-	register int fd, len;
+	register int fd;
+	ssize_t len;
 	FILE *pf, *popen();
 	struct stat stb;
 	static char buf[BUFSIZ];
@@ -261,9 +262,7 @@ static int remotecmd(rhost, luser, ruser, cmd)
 	char *cmd;
 {
 	int desc;
-#if	defined(DIRECT_RCMD)
 	static int port = -1;
-#endif	/* DIRECT_RCMD */
 
 	debugmsg(DM_MISC, "local user = %s remote user = %s\n", luser, ruser);
 	debugmsg(DM_MISC, "Remote command = '%s'\n", cmd);
@@ -290,11 +289,26 @@ static int remotecmd(rhost, luser, ruser, cmd)
 	if (becomeuser() != 0)
 		exit(1);
 #else	/* !DIRECT_RCMD */
-	debugmsg(DM_MISC, "Remote shell command = '%s'\n", path_remsh);
-	(void) signal(SIGPIPE, SIG_IGN);
-	desc = rshrcmd(&rhost, -1, luser, ruser, cmd, 0);
-	if (desc > 0)
+	if (geteuid() == 0 && strcmp(path_remsh, "/usr/bin/rsh") == 0) {
+		debugmsg(DM_MISC, "I am root, using rsh, therefore direct rcmd\n");
 		(void) signal(SIGPIPE, sighandler);
+
+		if (port < 0) {
+			struct servent *sp;
+		
+			if ((sp = getservbyname("shell", "tcp")) == NULL)
+				fatalerr("shell/tcp: unknown service");
+			port = sp->s_port;
+		}
+
+		desc = rcmd(&rhost, port, luser, ruser, cmd, 0);
+	} else {
+		debugmsg(DM_MISC, "Remote shell command = '%s'\n", path_remsh);
+		(void) signal(SIGPIPE, SIG_IGN);
+		desc = rshrcmd(&rhost, -1, luser, ruser, cmd, 0);
+		if (desc > 0)
+			(void) signal(SIGPIPE, sighandler);
+	}
 #endif	/* DIRECT_RCMD */
 
 	(void) alarm(0);
@@ -312,7 +326,7 @@ static int makeconn(rhost)
 	register char *ruser, *cp;
 	static char *cur_host = NULL;
 	extern char *locuser;
-	extern long min_freefiles, min_freespace;
+	extern int64_t min_freefiles, min_freespace;
 	extern char *remotemsglist;
 	char tuser[BUFSIZ], buf[BUFSIZ];
 	u_char respbuff[BUFSIZ];
@@ -403,13 +417,13 @@ static int makeconn(rhost)
 			return(0);
 	}
 	if (min_freespace) {
-		(void) sendcmd(C_SETCONFIG, "%c%d", SC_FREESPACE, 
+		(void) sendcmd(C_SETCONFIG, "%c%lld", SC_FREESPACE, 
 			       min_freespace);
 		if (response() < 0)
 			return(0);
 	}
 	if (min_freefiles) {
-		(void) sendcmd(C_SETCONFIG, "%c%d", SC_FREEFILES, 
+		(void) sendcmd(C_SETCONFIG, "%c%lld", SC_FREEFILES, 
 			       min_freefiles);
 		if (response() < 0)
 			return(0);
@@ -611,7 +625,7 @@ okname(name)
 		c = *cp;
 		if (c & 0200)
 			isbad = TRUE;
-		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-')
+		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-' && c != '.' )
 			isbad = TRUE;
 	}
 
