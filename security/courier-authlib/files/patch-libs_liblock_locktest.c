--- libs/liblock/locktest.c.orig	2022-11-25 10:00:03 UTC
+++ libs/liblock/locktest.c
@@ -3,6 +3,7 @@
 ** distribution information.
 */
 
+#include	<paths.h>
 #include	"liblock.h"
 #if	USE_FCNTL
 #include	"lockfcntl.c"
@@ -27,7 +28,7 @@ int main()
 
 int main()
 {
-#define FILENAME	"courier-imap.locktest.XXXXXXXXXX"
+#define FILENAME	"courier-authlib.locktest.XXXXXXXXXX"
 int	fd[2];
 pid_t	p;
 int	s;
@@ -36,7 +37,7 @@ int	f;
 	char *name;
 	const char *tmpdir;
 	if ((tmpdir = (char *)getenv("TMPDIR")) == NULL || !*tmpdir)
-		tmpdir = "/tmp";
+		tmpdir = _PATH_TMP;
 
 	if ((name=malloc(strlen(tmpdir)+sizeof(FILENAME)+1)) == NULL)
 	{
@@ -44,7 +45,8 @@ int	f;
 		exit(1);
 	}
 
-	(void)sprintf(name, "%s/%s", tmpdir, FILENAME);
+	(void)sprintf(name, "%s%s%s", tmpdir,
+		(tmpdir[strlen(tmpdir) - 1] == '/') ? "" : "/", FILENAME);
 
 	signal(SIGCHLD, SIG_DFL);
 	if (pipe(fd))
