--- hotsmtpd/commands_smtp.c.orig	Sat Dec 11 18:33:17 2004
+++ hotsmtpd/commands_smtp.c	Wed Dec 15 12:21:00 2004
@@ -199,7 +199,7 @@
   }
 
   /* Clean up after ourselves */
-  httpmail_destroy();
+  /*httpmail_destroy();*/
   if (body)
       free(body);
 }
