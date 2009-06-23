--- ./lib/mbox_mbf.c.orig	2003-03-05 02:33:12.000000000 -0500
+++ ./lib/mbox_mbf.c	2009-06-23 19:35:15.499808776 -0400
@@ -151,7 +151,10 @@
 			bytes -= len;
 			offset += len;
 			q[buffleft] = '\0';
-			p = strchr(buffer, '\n');
+			if ((p = strchr(buffer, '\n')) == NULL) {
+			    p = q + buffleft;
+			    continue;
+			}
 		}
 		*p++ = '\0';
 		if (*line == '\0') {
@@ -382,7 +385,14 @@
 			len = read(mbox->fd, offset, buffleft);
 			bytes -= len;
 			offset[len] = '\0';
-			p = strchr(buffer, '\n');
+			if ((p = strchr(buffer, '\n')) == NULL) {
+			    p = offset + len;
+			    if( (p - buffer) == 1 && buffer[0] == '.' )
+				sendline(SEND_BUF, "..");
+			    else
+				sendline(SEND_BUF, "%s", buffer);
+			    continue;
+			}
 		}
 		*p++ = '\0';
 		if (line[0] == '.' && line[1] == '\0') {
