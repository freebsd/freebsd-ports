--- src/accept.c.orig	Mon Jun 11 17:00:24 2001
+++ src/accept.c	Mon Jun 11 17:01:30 2001
@@ -2503,7 +2503,7 @@
   nothing on success. The function moan_smtp_batch() does not return -
   it exits from the program with a non-zero return code. */
 
-  else if (smtp_reply != NULL) moan_smtp_batch(NULL, smtp_reply);
+  else if (smtp_reply != NULL) moan_smtp_batch(NULL, "%s", smtp_reply);
   }
 
 /* Reset headers so that logging of rejects for a subsequent message doesn't
