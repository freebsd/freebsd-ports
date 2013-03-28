--- tty-keys.c.orig	2013-03-27 14:37:25.000000000 +0100
+++ tty-keys.c	2013-03-27 14:37:44.000000000 +0100
@@ -529,8 +529,6 @@
 	 * used. termios should have a better idea.
 	 */
 	bspace = tty->tio.c_cc[VERASE];
-	if (bspace != _POSIX_VDISABLE && key == bspace)
-		key = KEYC_BSPACE;
 
 	goto complete_key;
 
