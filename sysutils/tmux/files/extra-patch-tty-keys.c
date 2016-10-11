--- tty-keys.c.orig	2016-04-30 12:46:35 UTC
+++ tty-keys.c
@@ -628,8 +628,6 @@ complete_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && (key & KEYC_MASK_KEY) == bspace)
-		key = (key & KEYC_MASK_MOD) | KEYC_BSPACE;
 
 	/* Remove data from buffer. */
 	evbuffer_drain(tty->event->input, size);
