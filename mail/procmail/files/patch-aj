--- src/comsat.c.orig	Tue Sep 11 08:55:46 2001
+++ src/comsat.c	Wed Nov 17 09:44:12 2004
@@ -120,7 +120,7 @@
 { int s;const char*p;
   if(!csvalid||!buf)		  /* is comat on and set to a valid address? */
      return;
-  if(!*cslgname||strlen(cslgname)+2>linebuf)	       /* is $LOGNAME bogus? */
+  if(!cslgname||!*cslgname||strlen(cslgname)+2>linebuf)	       /* is $LOGNAME bogus? */
      return;
   if(!(p=folder?folder:cslastf))		     /* do we have a folder? */
      return;
