--- run.c	2001-03-07 20:37:47.000000000 +0300
+++ run.c	2008-06-22 00:17:05.000000000 +0400
@@ -77,6 +77,7 @@
 	return (*s1 ? ++s1 : 0);
 }
 
+#if !HAVE_EXECVPE
 static int execvpe (char *name, char **argv, char **envstr)
 {
 	static char *pathstr;
@@ -131,15 +132,28 @@
 		errno = EACCES;
 	return (-1);
 }
+#endif
 
 int runl (int silent, char *name, ...)
 {
 	va_list ap;
 	int err;
+	char **argv, **argp;
+	int argc;
 
+	argc = 1;
 	va_start (ap, name);
-	err = run (name, ap, execve, silent);
+	while (va_arg (ap, char *) != NULL)
+		argc++;
 	va_end (ap);
+	argv = (char **) malloc (argc * sizeof (char *));
+	argp = argv;
+	va_start (ap, name);
+	while ((*argp++ = va_arg (ap, char *)) != NULL);
+	*argp = NULL;
+	va_end (ap);
+	err = run (name, argv, execve, silent);
+	free (argv);
 	return err;
 }
 
