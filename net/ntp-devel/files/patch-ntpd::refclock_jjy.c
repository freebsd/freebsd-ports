--- ntpd/refclock_jjy.c.orig	Tue Dec  4 23:22:52 2001
+++ ntpd/refclock_jjy.c	Fri Jul 12 11:35:43 2002
@@ -704,7 +704,7 @@
 	 * Send "<ENQ>1J<ETX>" command
 	 */
 
-	if ( write ( pp->io.fd, "\x051J\x03", 4 ) != 4  ) {
+	if ( write ( pp->io.fd, "\0051J\003", 4 ) != 4  ) {
 		refclock_report ( peer, CEVNT_FAULT ) ;
 	}
 
