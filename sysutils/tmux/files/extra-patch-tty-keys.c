--- tty-keys.c.orig	2016-03-02 18:08:46 UTC
+++ tty-keys.c
@@ -572,8 +572,6 @@ first_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && key == bspace)
-		key = KEYC_BSPACE;
 
 	goto complete_key;
 
