--- src/tree.c.orig	Mon Jun 18 18:10:01 2001
+++ src/tree.c	Mon Jun 18 18:10:27 2001
@@ -25,7 +25,7 @@
 Returns:  points to prepared address string, in a fixed bit of store
 */
 
-static char prepared_address[256];
+static char prepared_address[512];
 
 static char *
 address_prepare(char *s)
