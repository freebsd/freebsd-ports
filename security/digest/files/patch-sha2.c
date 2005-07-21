--- sha2.c.orig	Thu Jul 21 00:39:56 2005
+++ sha2.c	Thu Jul 21 02:30:00 2005
@@ -588,7 +588,7 @@
 			/* Begin padding with a 1 bit: */
 			context->buffer[usedspace++] = 0x80;
 
-			if (usedspace < SHA256_SHORT_BLOCK_LENGTH) {
+			if (usedspace <= SHA256_SHORT_BLOCK_LENGTH) {
 				/* Set-up for the last transform: */
 				MEMSET_BZERO(&context->buffer[usedspace], SHA256_SHORT_BLOCK_LENGTH - usedspace);
 			} else {
