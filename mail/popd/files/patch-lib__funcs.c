$FreeBSD$

--- lib/funcs.c.orig	Mon Mar  3 21:10:19 2003
+++ lib/funcs.c	Wed Oct 15 11:18:01 2003
@@ -198,11 +198,11 @@
 		len = vsnprintf(p, MAXBUFLEN - (buffer - p), format, pvar);
 	}
 	va_end(pvar);
-	if (p - buffer + len + 3 > MAXBUFLEN) {
-		xwrite(buffer, p - buffer + len);
+	p += len;
+	if (p - buffer + 3 > MAXBUFLEN) {
+		xwrite(buffer, p - buffer);
 		p = buffer;
 	}
-	p += len;
 	*p++ = '\r';
 	*p++ = '\n';
 	if (flag == SEND_FLUSH) {

