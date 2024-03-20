--- src/docmd.c.orig	2001-10-22 13:29:22.000000000 -0700
+++ src/docmd.c	2024-03-19 17:06:30.415295000 -0700
@@ -132,7 +132,8 @@
 	register struct namelist *to;
 	time_t lmod;
 {
-	register int fd, len;
+	register int fd;
+	ssize_t len;
 	FILE *pf, *popen();
 	struct stat stb;
 	static char buf[BUFSIZ];
@@ -300,9 +301,7 @@
 	char *cmd;
 {
 	int desc;
-#if	defined(DIRECT_RCMD)
 	static int port = -1;
-#endif	/* DIRECT_RCMD */
 
 	debugmsg(DM_MISC, "local user = %s remote user = %s\n", luser, ruser);
 	debugmsg(DM_MISC, "Remote command = '%s'\n", cmd);
@@ -350,7 +349,7 @@
 	register char *ruser, *cp;
 	static char *cur_host = NULL;
 	extern char *locuser;
-	extern long min_freefiles, min_freespace;
+	extern int64_t min_freefiles, min_freespace;
 	extern char *remotemsglist;
 	char tuser[BUFSIZ], buf[BUFSIZ];
 	u_char respbuff[BUFSIZ];
@@ -445,13 +444,13 @@
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
@@ -663,7 +662,7 @@
 		c = *cp;
 		if (c & 0200)
 			isbad = TRUE;
-		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-')
+		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-' && c != '.' )
 			isbad = TRUE;
 	}
 
