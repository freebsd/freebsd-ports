
$FreeBSD$

--- src/tunnel.c.orig	Sun Dec  8 19:04:51 2002
+++ src/tunnel.c	Sun Mar  7 14:55:10 2004
@@ -554,9 +554,11 @@
 				ptr1 = strstr(boundary_buf, "boundary=");
 				if (ptr1 == 0) {
 					plist = plist->next;
-					safe_strcpy(boundary_buf, plist->line);
-					change_to_lower(boundary_buf);
-					ptr1 = strstr(boundary_buf, "boundary=");
+					if (plist) {
+						safe_strcpy(boundary_buf, plist->line);
+						change_to_lower(boundary_buf);
+						ptr1 = strstr(boundary_buf, "boundary=");
+					}
 				}
 
 				if (ptr1) {
