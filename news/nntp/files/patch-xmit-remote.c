--- xmit/remote.c.orig	Tue Jan  9 08:28:03 1996
+++ xmit/remote.c	Fri Jul 25 19:17:30 2003
@@ -71,11 +71,17 @@
 char	*sfgets();
 char	*rfgets();
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#include <unistd.h>
+#include <string.h>
+#else
 extern	int	errno;
+#endif
 extern	char	Debug;
 extern	char	*errmsg();
 extern	char	*strcpy();
-extern	void	log();
+extern	void	nntpdlog();
 
 /*
 ** send cmd to remote, terminated with a CRLF.
@@ -207,7 +213,7 @@
 		}
 		break;
 #else
-		log(L_WARNING, "no DECNET support compiled in");
+		nntpdlog(L_WARNING, "no DECNET support compiled in");
 		return(FAIL);
 #endif
 	case T_FD:
@@ -220,29 +226,29 @@
 		switch(socket0) {
 		case NOHOST:
 			sprintf(buf, "%s host unknown", host);
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 			return(FAIL);
 		case NOSERVICE:
 			sprintf(buf, "%s service unknown: %s", host, service);
-			log(L_WARNING, buf);
+			nntpdlog(L_WARNING, buf);
 			return(FAIL);
 		case FAIL:
 			sprintf(buf, "%s hello: %s", host, errmsg(errno));
-			log(L_NOTICE, buf);
+			nntpdlog(L_NOTICE, buf);
 			return(FAIL);
 		}
 	}
 
 	if ((socket1 = dup(socket0)) < 0) {
 		sprintf(buf, "dup(%d): %s", socket0, errmsg(errno));
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		(void) close(socket0);
 		return(FAIL);
 	}
 
 	if ((rmt_rd = fdopen(socket0, rmode)) == (FILE *)NULL) {
 		sprintf(buf, e_fdopen, socket0, rmode);
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		(void) close(socket0);
 		(void) close(socket1);
 		return(FAIL);
@@ -250,7 +256,7 @@
 
 	if ((rmt_wr = fdopen(socket1, wmode)) == (FILE *)NULL) {
 		sprintf(buf, e_fdopen, socket1, wmode);
-		log(L_WARNING, buf);
+		nntpdlog(L_WARNING, buf);
 		(void) fclose(rmt_rd);
 		rmt_rd = (FILE *)NULL;
 		(void) close(socket1);
@@ -270,7 +276,7 @@
 			char	err[BUFSIZ];
 
 			sprintf(err, "%s greeted us with %s", host, buf);
-			log(L_NOTICE, err);
+			nntpdlog(L_NOTICE, err);
 		}
 		goodbye(DONT_WAIT);
 		return(FAIL);
@@ -403,7 +409,7 @@
 ** with appropriate RFC822 filtering (e.g. CRLF line termination,
 ** and dot escaping). Return FALSE if something went wrong.
 */
-sendfile(fp)
+my_sendfile(fp)
 FILE	*fp;
 {
 	register int	c;
@@ -440,7 +446,7 @@
         mbufr = mmap (0, sbuf.st_size, PROT_READ, MAP_PRIVATE, fileno(fp), 0);
         if(mbufr == (char *) -1){
 		sprintf(buf, "sendfile: mmap failed: %s", errmsg(errno));
-		log(L_NOTICE, buf);
+		nntpdlog(L_NOTICE, buf);
                 return(FALSE);
         }
 
