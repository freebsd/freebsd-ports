$FreeBSD$

--- main.c.orig	Thu Mar 28 20:57:50 2002
+++ main.c	Thu Mar 28 20:58:31 2002
@@ -69,7 +69,7 @@
 int     pseudo_route    = 0;
 
 int	in_fd		= 0;
-FILE	* out_fd	= stdout;
+FILE	* out_fd;
 FILE	* char_fd	= NULL;
 FILE	* conf_fd	= NULL;
 off_t   pz;
@@ -83,7 +83,7 @@
   int   no_run = FALSE;
   char *cmailer = NULL;
   char *member = NULL;
-
+	out_fd = stdout;
 #ifdef	HAVE_GETPAGESIZE
 	pz = (off_t) getpagesize();
 #elif	defined(hpux) || defined(_AUX_SOURCE)
