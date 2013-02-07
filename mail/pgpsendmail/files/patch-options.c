--- options.c.orig	1994-10-29 17:09:46.000000000 +0900
+++ options.c	2012-10-24 16:09:09.000000000 +0900
@@ -158,7 +158,9 @@
     char config_filename[STRING_LENGTH];
     char txt[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     (void) sprintf (config_filename, "%s/PGPsendmail.config", pgppath);
     if ( ( fp = fopen (config_filename, "r") ) == NULL )
