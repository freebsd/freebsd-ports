Index: smrsh.c
===================================================================
RCS file: /cvs/smrsh/smrsh.c,v
retrieving revision 8.58
diff -u -r8.58 smrsh.c
--- smrsh/smrsh.c	25 May 2002 02:41:31 -0000	8.58
+++ smrsh/smrsh.c	24 Sep 2002 23:58:16 -0000
@@ -57,6 +57,8 @@
 #include <sm/limits.h>
 #include <sm/string.h>
 #include <sys/file.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <string.h>
 #include <ctype.h>
 #include <errno.h>
@@ -145,6 +147,7 @@
 	char *newenv[2];
 	char pathbuf[1000];
 	char specialbuf[32];
+	struct stat st;
 
 #ifndef DEBUG
 # ifndef LOG_MAIL
@@ -302,6 +305,38 @@
 			(void) sm_io_fprintf(smioout, SM_TIME_DEFAULT,
 					     "Trying %s\n", cmdbuf);
 #endif /* DEBUG */
+			if (stat(cmdbuf, &st) < 0)
+			{
+				/* can't stat it */
+				(void) sm_io_fprintf(smioerr, SM_TIME_DEFAULT,
+						     "%s: %s not available for sendmail programs (stat failed)\n",
+						      prg, cmd);
+				if (p != NULL)
+					*p = ' ';
+#ifndef DEBUG
+				syslog(LOG_CRIT, "uid %d: attempt to use %s (stat failed)",
+				       (int) getuid(), cmd);
+#endif /* ! DEBUG */
+				exit(EX_UNAVAILABLE);
+			}
+			if (!S_ISREG(st.st_mode)
+#ifdef S_ISLNK
+			    && !S_ISLNK(st.st_mode)
+#endif /* S_ISLNK */
+			   )
+			{
+				/* can't stat it */
+				(void) sm_io_fprintf(smioerr, SM_TIME_DEFAULT,
+						     "%s: %s not available for sendmail programs (not a file)\n",
+						      prg, cmd);
+				if (p != NULL)
+					*p = ' ';
+#ifndef DEBUG
+				syslog(LOG_CRIT, "uid %d: attempt to use %s (not a file)",
+				       (int) getuid(), cmd);
+#endif /* ! DEBUG */
+				exit(EX_UNAVAILABLE);
+			}
 			if (access(cmdbuf, X_OK) < 0)
 			{
 				/* oops....  crack attack possiblity */
