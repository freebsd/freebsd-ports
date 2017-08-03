--- misc/openvas_proctitle.c	2017-08-03 14:59:39.601267000 -0500
+++ misc/openvas_proctitle.c	2017-08-03 15:39:18.158798000 -0500
@@ -29,8 +29,6 @@
 
 #include "openvas_proctitle.h"
 
-extern const char *__progname;
-extern const char *__progname_full;
 static int argv_len;
 static char **old_argv;
 extern char **environ;
@@ -47,14 +45,10 @@
 {
   int i = 0;
   char **envp = environ;
-  char *new_progname, *new_progname_full;
 
   if (argv == NULL)
     return;
 
-  new_progname = strdup (__progname);
-  new_progname_full = strdup (__progname_full);
-
   /* Move environ to new memory, to be able to reuse older one. */
   while (envp[i]) i++;
   environ = g_malloc0 (sizeof (char *) * (i + 1));
@@ -70,11 +64,6 @@
     argv_len = envp[i-1] + strlen (envp[i-1]) - old_argv[0];
   else
     argv_len = old_argv[argc-1] + strlen (old_argv[argc-1]) - old_argv[0];
-
-  /* Seems like these are in the moved environment, so reset them.  Idea from
-   * proctitle.cpp in KDE libs.  */
-  __progname = new_progname;
-  __progname_full = new_progname_full;
 }
 
 /**
