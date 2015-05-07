--- tty-keys.c.orig	2015-05-05 20:21:51 UTC
+++ tty-keys.c
@@ -556,8 +556,6 @@ first_key:
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && key == bspace)
-		key = KEYC_BSPACE;
 
 	goto complete_key;
 
