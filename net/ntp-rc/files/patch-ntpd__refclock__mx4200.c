--- ntpd/refclock_mx4200.c.orig	2014-12-19 11:56:52 UTC
+++ ntpd/refclock_mx4200.c
@@ -1572,7 +1572,7 @@ mx4200_debug(struct peer *peer, char *fm
 		 * Print debug message to stdout
 		 * In the future, we may want to get get more creative...
 		 */
-		mvprintf(fmt, ap);
+		vprintf(fmt, ap);
 
 		va_end(ap);
 	}
@@ -1613,11 +1613,11 @@ mx4200_send(peer, fmt, va_alist)
 
 	cp = buf;
 	*cp++ = '$';
-	n = VSNPRINTF((cp, sizeof(buf) - 1, fmt, ap));
+	n = vsnprintf(cp, sizeof(buf) - 1, fmt, ap);
 	ck = mx4200_cksum(cp, n);
 	cp += n;
 	++n;
-	n += SNPRINTF((cp, sizeof(buf) - n - 5, "*%02X\r\n", ck));
+	n += snprintf(cp, sizeof(buf) - n - 5, "*%02X\r\n", ck);
 
 	m = write(pp->io.fd, buf, (unsigned)n);
 	if (m < 0)
