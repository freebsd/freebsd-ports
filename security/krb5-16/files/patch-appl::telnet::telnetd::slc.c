--- appl/telnet/telnetd/slc.c.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/slc.c	Mon Jul 23 16:45:51 2001
@@ -198,7 +198,7 @@
 			(void) sprintf((char *)slcptr, "%c%c", IAC, SE);
 			slcptr += 2;
 			len = slcptr - slcbuf;
-			writenet(slcbuf, len);
+			output_datalen(slcbuf, len);
 			netflush();  /* force it out immediately */
 			DIAG(TD_OPTIONS, printsub('>', slcbuf+2, len-2););
 		}
