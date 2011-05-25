--- tty-keys.c.orig	2010-06-04 08:45:52.000000000 +0800
+++ tty-keys.c	2010-06-04 08:46:45.000000000 +0800
@@ -456,8 +456,6 @@
 		 * used. termios should have a better idea.
 		 */
 		bspace = tty->tio.c_cc[VERASE];
-		if (bspace != _POSIX_VDISABLE && key == bspace)
-			key = KEYC_BSPACE;
 		goto handle_key;
 	}
 
