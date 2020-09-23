--- src/main.c.orig	2003-08-24 19:23:50 UTC
+++ src/main.c
@@ -55,8 +55,9 @@ pcre_extra *hints;
 char *boxname, *outboxname, *pipecmd, *tmpfilename;
 int maildir_count = 0;
 int count = 0;
-void *tmpp;
+FILE *tmpp;
 checksum_t *cs;
+option_t config;
 
 int
 main (int argc, char **argv)
@@ -238,8 +239,7 @@ main (int argc, char **argv)
       config.pid = (int) getpid ();
     }
 
-  cs = (checksum_t *) xmalloc (sizeof (checksum_t));
-  cs->md5 = (char **) xcalloc (1, sizeof (char **));
+  cs = xmalloc (sizeof (checksum_t));
   cs->n = 0;
 
   if (optind < argc && ! haveregex)
