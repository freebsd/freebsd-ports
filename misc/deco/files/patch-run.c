--- run.c	Wed Mar  7 19:37:47 2001
+++ run.c	Sun Dec  5 22:51:12 2004
@@ -136,10 +136,22 @@
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
 
