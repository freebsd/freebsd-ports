--- tty-keys.c.orig	2019-05-01 06:07:32 UTC
+++ tty-keys.c
@@ -704,8 +704,6 @@ complete_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && (key & KEYC_MASK_KEY) == bspace)
-		key = (key & KEYC_MASK_MOD) | KEYC_BSPACE;
 
 	/* Remove data from buffer. */
 	evbuffer_drain(tty->in, size);
