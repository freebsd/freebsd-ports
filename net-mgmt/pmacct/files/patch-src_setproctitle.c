--- src/setproctitle.c.orig	2022-12-31 19:17:17 UTC
+++ src/setproctitle.c
@@ -38,8 +38,7 @@ extern char *__progname;
  * NEWSTR -- Create a copy of a C string
  */
 
-char *spt_newstr(s)
-const char *s;
+char *spt_newstr(const char *s)
 {
   size_t l;
   char *n;
@@ -81,10 +80,7 @@ void
 static char	*LastArgv = NULL;	/* end of argv */
 
 void
-initsetproctitle(argc, argv, envp)
-	int argc;
-	char **argv;
-	char **envp;
+initsetproctitle(int argc, char **argv, char **envp)
 {
 	register int i;
 	extern char **environ;
