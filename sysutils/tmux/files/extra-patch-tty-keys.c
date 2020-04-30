--- tty-keys.c.orig	2020-04-24 08:57:17 UTC
+++ tty-keys.c
@@ -719,8 +719,6 @@ complete_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && (key & KEYC_MASK_KEY) == bspace)
-		key = (key & KEYC_MASK_MOD) | KEYC_BSPACE;
 
 	/* Remove data from buffer. */
 	evbuffer_drain(tty->in, size);
