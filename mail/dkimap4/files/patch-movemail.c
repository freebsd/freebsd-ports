--- movemail/movemail.c.orig	Tue Jul  4 23:07:49 2000
+++ movemail/movemail.c	Sun May 27 02:21:01 2001
@@ -155,7 +155,7 @@
 /* Nonzero means this is name of a lock file to delete on fatal error.  */
 char *delete_lockname;
 
-void
+int
 main (argc, argv)
      int argc;
      char **argv;
@@ -258,7 +258,7 @@
     p--;
   *p = 0;
   strcpy (p, "EXXXXXX");
-  mktemp (tempname);
+  mkstemp (tempname);
   unlink (tempname);
 
   while (1)
@@ -840,18 +840,3 @@
 }
 
 #endif /* MAIL_USE_POP */
-
-#ifndef HAVE_STRERROR
-char *
-strerror (errnum)
-     int errnum;
-{
-  extern char *sys_errlist[];
-  extern int sys_nerr;
-
-  if (errnum >= 0 && errnum < sys_nerr)
-    return sys_errlist[errnum];
-  return (char *) "Unknown error";
-}
-
-#endif /* ! HAVE_STRERROR */
