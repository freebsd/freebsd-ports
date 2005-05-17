--- liblock/locktest.c.orig	Mon Dec  6 14:18:55 1999
+++ liblock/locktest.c	Sun May 15 08:00:42 2005
@@ -5,6 +5,7 @@
 
 /* $Id */
 
+#include	<paths.h>
 #include	"liblock.h"
 #if	USE_FCNTL
 #include	"lockfcntl.c"
@@ -20,11 +21,23 @@
 
 int main()
 {
+#define FILENAME	"courier-authlib.locktest.XXXXX"
 int	fd[2];
 pid_t	p;
 int	s;
 int	f;
 
+	char *name;
+	const char *tmpdir;
+	if ((tmpdir = (char *)getenv("TMPDIR")) == NULL)
+		tmpdir = _PATH_TMP;
+	(void)asprintf(&name, "%s%s%s", tmpdir,
+		(tmpdir[strlen(tmpdir) - 1] == '/') ? "" : "/", FILENAME);
+	if (name == NULL) {
+		perror("get filename");
+		exit(1);
+	}
+
 	signal(SIGCHLD, SIG_DFL);
 	if (pipe(fd))
 	{
@@ -32,6 +45,12 @@
 		return (1);
 	}
 
+	if ((f=mkstemp(name)) < 0)
+	{
+		perror("open");
+		exit(1);
+	}
+
 	if ((p=fork()) == (pid_t)-1)
 	{
 		perror("fork");
@@ -46,7 +65,7 @@
 		read(fd[0], &c, 1);
 		close(fd[0]);
 
-		if ((f=open("conftest.lock", O_RDWR|O_CREAT, 0644)) < 0)
+		if ((f=open(name, O_RDWR)) < 0)
 		{
 			perror("open");
 			exit(1);
@@ -56,22 +75,18 @@
 		if (ll_lockfd(f, ll_writelock, 0, 0))
 		{
 			close(f);
+			unlink(name);
 			exit(0);
 		}
 		close(f);
 		exit(1);
 	}
-	
-	if ((f=open("conftest.lock", O_RDWR|O_CREAT, 0644)) < 0)
-	{
-		perror("open");
-		exit(1);
-	}
 
 	if (ll_lockfd(f, ll_writelock, 0, 0))
 	{
 		perror("lock");
 		close(f);
+		unlink(name);
 		exit(1);
 	}
 	close(fd[1]);
