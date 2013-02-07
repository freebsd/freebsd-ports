--- pgpdaemon.c.orig	1995-01-04 14:15:01.000000000 +0900
+++ pgpdaemon.c	2012-10-24 16:19:34.000000000 +0900
@@ -156,7 +156,7 @@
 #  if defined(sparc) || defined(linux)
 #    define MAIL_SPOOL_DIR "/var/spool/mail"
 #  else
-#    if defined(__bsdi__) || ( defined(sparc) && defined(__sysvr4__) )
+#    if defined(__bsdi__) || defined(__FreeBSD__) || ( defined(sparc) && defined(__sysvr4__) )
 #      define MAIL_SPOOL_DIR "/var/mail"
 #    else
 #      define MAIL_SPOOL_DIR "/usr/spool/mail"
@@ -229,7 +229,7 @@
 
 /*  Now everything else may follow.  */
 
-void main (argc, argv, envp)
+int main (argc, argv, envp)
 int argc;
 char *argv[];
 char *envp[];
@@ -268,7 +268,9 @@
     ERRNO_TYPE errno;
     static char usage_string[] =
     "Usage:\tpgpdaemon [-mailwait] [-detach] [-pgppath <path>]";
+#if 0
     extern char *sys_errlist[];
+#endif
 
     /*  Read arguments  */
     for (count = 1; count < argc; ++count)
@@ -545,7 +547,9 @@
     extern char passphrase[STRING_LENGTH];
     extern char *secring_buf;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     /*  Connect to output pipe  */
     for (count = 0; (count < 2) && (out_fd < 0); ++count)
@@ -782,7 +786,9 @@
     extern char my_userid[STRING_LENGTH];
     extern char passphrase[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     /*  Setup arguments to PGP  */
     if (sign)
@@ -879,7 +885,9 @@
     char lock_name[STRING_LENGTH];
     char mlk_name[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     (void) strcpy (lock_name, filename);
     (void) strcat (lock_name, ".lock");
@@ -956,7 +964,9 @@
     struct flock fl;
 #endif
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if (no_filelocking) return (TRUE);
 #undef LOCKING_WORKS
@@ -1032,7 +1042,9 @@
     extern char outgoing_spool[STRING_LENGTH];
     extern char passphrase[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if (stat (incoming_spool, &statbuf) != 0)
     {
@@ -1436,7 +1448,9 @@
     extern char incoming_spool[STRING_LENGTH];
     extern char outgoing_spool[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     (void) sprintf (config_filename, "%s/PGPdaemon.config", pgppath);
     if ( ( fp = fopen (config_filename, "r") ) == NULL )
@@ -1587,7 +1601,9 @@
     extern char *secring_buf;
     extern char *pgppath;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     (void) sprintf (filename, "%s/secring.pgp", pgppath);
     if ( ( fd = open (filename, O_WRONLY | O_CREAT | O_EXCL,
