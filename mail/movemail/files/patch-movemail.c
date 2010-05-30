--- movemail.c.orig	1997-09-05 18:15:56.000000000 +0200
+++ movemail.c	2010-05-29 14:19:38.000000000 +0200
@@ -63,6 +63,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include "syswait.h"
+#include <string.h>
 #ifdef MAIL_USE_POP
 #include "pop.h"
 #endif
@@ -529,13 +530,13 @@
   server = pop_open (0, user, password, POP_NO_GETPASS);
   if (! server)
     {
-      error (pop_error);
+      error ("%s",pop_error);
       return (1);
     }
 
   if (pop_stat (server, &nmsgs, &nbytes))
     {
-      error (pop_error);
+      error ("%s", pop_error);
       return (1);
     }
 
@@ -568,7 +569,7 @@
       mbx_delimit_begin (mbf);
       if (pop_retr (server, i, mbx_write, mbf) != OK)
 	{
-	  error (Errmsg);
+	  error ("%s",Errmsg);
 	  close (mbfi);
 	  return (1);
 	}
@@ -607,7 +608,7 @@
     {
       if (pop_delete (server, i))
 	{
-	  error (pop_error);
+	  error ("%s",pop_error);
 	  pop_close (server);
 	  return (1);
 	}
@@ -615,7 +616,7 @@
 
   if (pop_quit (server))
     {
-      error (pop_error);
+      error ("%s",pop_error);
       return (1);
     }
     
