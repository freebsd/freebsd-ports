--- appl/telnet/telnetd/utility.c.orig	Wed Jan  9 14:26:59 2002
+++ appl/telnet/telnetd/utility.c	Fri Jan 11 13:10:33 2002
@@ -408,18 +408,25 @@
 int
 netwrite(const char *buf, size_t len)
 {
-	size_t remain;
+	int remaining, copied;
+	
+	remaining = BUFSIZ - (nfrontp - netobuf);
+	while (len > 0) {
+		/* Free up enough space if the room is too low*/
+		if ((len > BUFSIZ ? BUFSIZ : len) > remaining) {
+			netflush();
+			remaining = BUFSIZ - (nfrontp - netobuf);
+		}
 
-	remain = sizeof(netobuf) - (nfrontp - netobuf);
-	if (remain < len) {
-		netflush();
-		remain = sizeof(netobuf) - (nfrontp - netobuf);
+		/* Copy out as much as will fit */
+		copied = remaining > len ? len : remaining;
+		memmove(nfrontp, buf, copied);
+		nfrontp += copied;
+		len -= copied;
+		remaining -= copied;
+		buf += copied;
 	}
-	if (remain < len)
-		return 0;
-	memcpy(nfrontp, buf, len);
-	nfrontp += len;
-	return len;
+	return copied;
 }
 
 /*
