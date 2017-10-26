--- tty-keys.c.orig	2017-08-29 11:54:14 UTC
+++ tty-keys.c
@@ -679,8 +679,6 @@ complete_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && (key & KEYC_MASK_KEY) == bspace)
-		key = (key & KEYC_MASK_MOD) | KEYC_BSPACE;
 
 	/* Remove data from buffer. */
 	evbuffer_drain(tty->in, size);
