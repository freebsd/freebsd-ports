--- bin/hpuifilter.c.orig	2020-08-20 10:37:10 UTC
+++ bin/hpuifilter.c
@@ -119,7 +119,7 @@
 #define	BUFSZ	(LINE_MAX * 2)
 #define	ESC	0x1b
 
-char		**environ,
+char		**enviro,
 		*progname;
 int		debug,
 		sigrx,
@@ -162,7 +162,7 @@ main(int argc, char **argv, char **ev)
     struct pollfd	pfds[3];
     struct termios	tios;
 
-    environ = ev;
+    enviro = ev;
 
     /* get just the basename() of our exec() name and strip a .* off the end */
     if ((progname = strrchr(argv[0], '/')) != NULL)
@@ -695,10 +695,10 @@ unsetenv(const char *name)
    char	**victim,
 	**end;
    int	len;
-   if (environ == NULL)
+   if (enviro == NULL)
 	return(0);
    len = strlen(name);
-   victim = environ;
+   victim = enviro;
    while (*victim != NULL) {
 	if (strncmp(name, *victim, len) == 0 && victim[0][len] == '=')
 	    break;
