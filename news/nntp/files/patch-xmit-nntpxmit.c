--- xmit/nntpxmit.c.orig	1994-12-03 23:37:58.000000000 +0100
+++ xmit/nntpxmit.c	2014-02-07 22:23:30.000000000 +0100
@@ -66,6 +66,7 @@
 #include "../conf.h"
 #include <stdio.h>
 #include <errno.h>
+#include <unistd.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/time.h>
@@ -75,7 +76,10 @@
 #include <sys/times.h>
 extern	time_t	time();
 #endif
+#ifndef __FreeBSD__
 #include <sys/file.h>
+#include <string.h>
+#endif
 #include <fcntl.h>
 #include <signal.h>
 #ifdef USG
@@ -105,7 +109,9 @@
 SIGRET	catchsig();
 void	restsig();
 void	logstats();
-void	log();
+void	nntpdlog();
+void	cleanup();
+void	rewrite();
 int	interrupted();
 
 /*
@@ -148,6 +154,7 @@
 
 double Tbegin, Tend;		/* transfer timestamps */
 
+#ifndef __FreeBSD__
 extern	int	errno;
 extern 	int	strncmp();
 extern	char	*rindex();
@@ -155,6 +162,7 @@
 extern	char	*mktemp();
 extern	char	*strcpy();
 extern	char	*strcat();
+#endif
 
 main(ac, av)
 int	ac;
@@ -298,10 +306,10 @@
 		"%s stats %lu offered %lu accepted %lu rejected %lu failed",
 		Host, Stats.offered, Stats.accepted, Stats.rejected,
 		Stats.failed);
-	log(L_INFO, buf);
+	nntpdlog(L_INFO, buf);
 	sprintf(buf, "%s xmit user %.3f system %.3f elapsed %.3f",
 		Host, (user - ouser), (sys - osys), (Tend - Tbegin));
-	log(L_INFO, buf);
+	nntpdlog(L_INFO, buf);
 	/* reset reference point */
 	Tbegin = Tend;	
 	ouser = user;
@@ -336,7 +344,7 @@
 		char	buf[BUFSIZ];
 
 		sprintf(buf, E_fopen, file, mode, errmsg(errno));
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		return(FALSE);
 	}
 
@@ -437,7 +445,7 @@
 		if (fp == NULL && errno != ENOENT) {
 			/* Worse than "No such file or directory"? */
 			sprintf(buf, E_fopen, file, "r", errmsg(errno));
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 			goodbye(DONT_WAIT);
 			exit(EX_OSERR);
 		}
@@ -445,13 +453,13 @@
 			/* Hmph. The file didn't exist. */
 			error = sendcmd(".");
 		} else {
-			error = !sendfile(fp);
+			error = !my_sendfile(fp);
 			/* Leave this open in case we need to requeue it. */
 		}
 		if (error) {
 			sprintf(buf, "%s xfer: sendfile: %s",
 				host, errmsg(errno));
-			log(L_NOTICE, buf);
+			nntpdlog(L_NOTICE, buf);
 			Stats.failed++;
 			if (fp) { (void) fclose(fp); fp = NULL; }
 			return(FALSE);
@@ -466,12 +474,12 @@
 			if (code < 0) {
 				if (errno > 0) {
 					sprintf(buf, e_xfer, host, errmsg(errno));
-					log(L_NOTICE, buf);
+					nntpdlog(L_NOTICE, buf);
 				} else {
 					char errbuf[BUFSIZ];
 
 					sprintf(errbuf, e_xfer, host, buf);
-					log(L_NOTICE, errbuf);
+					nntpdlog(L_NOTICE, errbuf);
 				}
 				if (fp) { (void) fclose(fp); fp = NULL; }
 				return(FALSE);
@@ -495,14 +503,14 @@
 		if (code < 0) {
 			if (errno > 0) {
 				sprintf(buf, e_xfer, host, errmsg(errno));
-				log(L_NOTICE, buf);
+				nntpdlog(L_NOTICE, buf);
 			} else {
 				sprintf(buf, e_xfer, host, "ihave");
-				log(L_NOTICE, buf);
+				nntpdlog(L_NOTICE, buf);
 			}
 		} else {
 			sprintf(buf, "%s improper response to IHAVE: %d while offering %s", host, code, Article);
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 			if (fp) { (void) fclose(fp); fp = NULL; }
 		}
 		return(FALSE);
@@ -515,8 +523,10 @@
 errmsg(code)
 int code;
 {
+#ifndef __FreeBSD__
 	extern int sys_nerr;
 	extern char *sys_errlist[];
+#endif
 	static char ebuf[6+5+1];
 
 	if (code > sys_nerr || code < 0) {
@@ -769,13 +779,13 @@
 		** communications with the remote either.
 		*/
 		sprintf(buf, "%s: message-id missing!", Article);
-		log(L_DEBUG, buf);
+		nntpdlog(L_DEBUG, buf);
 		return(ERR_GOTIT);
 	}
 
 	if (!msgid_ok(id)) {
 		sprintf(buf, "%s: message-id syntax error: %s", Article, id);
-		log(L_DEBUG, buf);
+		nntpdlog(L_DEBUG, buf);
 		return(ERR_GOTIT);
 	}
 
@@ -836,7 +846,7 @@
 /*
 ** OK, clean up any mess and requeue failed articles
 */
-cleanup()
+void cleanup()
 {
 	dprintf(stderr, "%s: cleanup()\n", Pname);
 	if (Qfp == (FILE *)NULL || Qfile == (char *)NULL)
@@ -856,7 +866,7 @@
 				char	buf[BUFSIZ];
 
 				sprintf(buf, E_unlk, Qfile, errmsg(errno));
-				log(L_WARNING, buf);
+				nntpdlog(L_WARNING, buf);
 			}
 		}
 		FCLOSE(Qfp);
@@ -908,7 +918,7 @@
 ** account is supposed to own netnews), the resultant file will be the
 ** wrong ownership, permissions, etc.
 */
-rewrite()
+void rewrite()
 {
 	register ll_t	*lp;
 	register FILE	*tmpfp;
@@ -925,7 +935,7 @@
 
 	if ((tmpfp = fopen(tempfile, mode)) == (FILE *)NULL) {
 		sprintf(buf, E_fopen, tempfile, mode, errmsg(errno));
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		FCLOSE(Qfp);
 		return;
 	}
@@ -962,12 +972,12 @@
 	*/
 	if (ferror(tmpfp)) {
 		sprintf(buf, "rewrite(): copy to %s failed", tempfile);
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		(void) fclose(tmpfp);
 		FCLOSE(Qfp);
 		if (unlink(tempfile) < 0) {
 			sprintf(buf, E_unlk, tempfile, errmsg(errno));
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 		}
 		requeue((char *)NULL,(char *)NULL);	/* reset */
 		return;
@@ -978,12 +988,12 @@
 	rewind(Qfp);
 	if (ftruncate(fileno(Qfp), (off_t)0) < 0) {
 		sprintf(buf, "ftruncate(%s, 0): %s", Qfile, errmsg(errno));
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		FCLOSE(Qfp);
 		(void) fclose(tmpfp);
 		if (unlink(tempfile) < 0) {
 			sprintf(buf, E_unlk, tempfile, errmsg(errno));
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 		}
 		requeue((char *)NULL,(char *)NULL);	/* reset */
 		return;
@@ -992,11 +1002,11 @@
 	FCLOSE(Qfp);	/* we just nuked our lock here (lockfd) */
 	if ((Qfp = fopen(Qfile, mode)) == (FILE *)NULL) {
 		sprintf(buf, E_fopen, Qfile, mode, errmsg(errno));
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		(void) fclose(tmpfp);
 		if (unlink(tempfile) < 0) {
 			sprintf(buf, E_unlk, tempfile, errmsg(errno));
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 		}
 		requeue((char *)NULL,(char *)NULL);	/* reset */
 		return;
@@ -1012,13 +1022,13 @@
 	(void) fflush(Qfp);
 	if (ferror(Qfp)) {
 		sprintf(buf, "rewrite(): copy to %s failed", Qfile);
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 	}
 	(void) fclose(tmpfp);
 	FCLOSE(Qfp);
 	if (unlink(tempfile) < 0) {
 		sprintf(buf, E_unlk, tempfile, errmsg(errno));
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 	}
 	requeue((char *)NULL,(char *)NULL);		/* reset */
 	dprintf(stderr, "%s: rewrite(%s): done\n", Pname, Qfile);
@@ -1040,7 +1050,7 @@
 	catchsig(SIG_IGN);	/* for System V - hope we're quick enough */
 #endif	/* RELSIG */
 	sprintf(buf, "%s signal %d", Host, sig);
-	log(L_NOTICE, buf);
+	nntpdlog(L_NOTICE, buf);
 	requeue(Article,(char *)NULL);
 	cleanup();
 	if (Report_Stats)
@@ -1092,7 +1102,7 @@
 ** log stuff
 */
 void
-log(importance, error)
+nntpdlog(importance, error)
 int	importance;
 char	*error;
 {
@@ -1131,7 +1141,7 @@
 	if (lockf(fd, (non_blocking ? F_TLOCK : F_LOCK), 0) < 0) {
 		if (errno != EACCES) {
 			sprintf(buf, "lockf(%s): %s\n", file, errmsg(errno));
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 		}
 		return(FALSE);
 	}
@@ -1141,7 +1151,7 @@
 	if (flock(fd, LOCK_EX|(non_blocking ? LOCK_NB : 0)) < 0) {
 		if (errno != EWOULDBLOCK) {
 			sprintf(buf, "flock(%s): %s\n", file, errmsg(errno));
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 		}
 		return(FALSE);
 	}
