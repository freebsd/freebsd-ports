--- ntpd/refclock_jjy.c.orig	Thu Jan 17 10:40:53 2002
+++ ntpd/refclock_jjy.c	Fri Jul 12 11:37:44 2002
@@ -701,7 +701,7 @@
 	 * Send "<ENQ>1J<ETX>" command
 	 */
 
-	if ( write ( pp->io.fd, "\x051J\x03", 4 ) != 4  ) {
+	if ( write ( pp->io.fd, "\0051J\003", 4 ) != 4  ) {
 		refclock_report ( peer, CEVNT_FAULT ) ;
 	}
 
