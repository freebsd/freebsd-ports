--- tty-keys.c.orig	2015-09-27 09:42:08 UTC
+++ tty-keys.c
@@ -545,8 +545,6 @@ first_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && key == bspace)
-		key = KEYC_BSPACE;
 
 	goto complete_key;
 
