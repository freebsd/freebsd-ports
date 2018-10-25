--- tty-keys.c.orig	2018-10-17 18:28:08 UTC
+++ tty-keys.c
@@ -681,8 +681,6 @@ complete_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && (key & KEYC_MASK_KEY) == bspace)
-		key = (key & KEYC_MASK_MOD) | KEYC_BSPACE;
 
 	/* Remove data from buffer. */
 	evbuffer_drain(tty->in, size);
