--- libs/liblock/locktest.c.orig	2014-07-13 13:58:08 UTC
+++ libs/liblock/locktest.c
@@ -3,6 +3,7 @@
 ** distribution information.
 */
 
+#include	<paths.h>
 #include	"liblock.h"
 #if	USE_FCNTL
 #include	"lockfcntl.c"
@@ -20,7 +21,7 @@
 
 int main()
 {
-#define FILENAME	"courier-imap.locktest.XXXXXXXXXX"
+#define FILENAME	"courier-authlib.locktest.XXXXXXXXXX"
 int	fd[2];
 pid_t	p;
 int	s;
@@ -29,7 +30,7 @@ int	f;
 	char *name;
 	const char *tmpdir;
 	if ((tmpdir = (char *)getenv("TMPDIR")) == NULL || !*tmpdir)
-		tmpdir = "/tmp";
+		tmpdir = _PATH_TMP;
 
 	if ((name=malloc(strlen(tmpdir)+sizeof(FILENAME)+1)) == NULL)
 	{
@@ -37,7 +38,8 @@ int	f;
 		exit(1);
 	}
 
-	(void)sprintf(name, "%s/%s", tmpdir, FILENAME);
+	(void)sprintf(name, "%s%s%s", tmpdir,
+		(tmpdir[strlen(tmpdir) - 1] == '/') ? "" : "/", FILENAME);
 
 	signal(SIGCHLD, SIG_DFL);
 	if (pipe(fd))
