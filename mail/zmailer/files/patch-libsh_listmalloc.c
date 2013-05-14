--- libsh/listmalloc.c.orig	2013-05-14 09:22:34.000000000 +0200
+++ libsh/listmalloc.c	2013-05-14 10:13:43.000000000 +0200
@@ -273,7 +273,7 @@
 
 	if (depth > deepest_dsw)
 		deepest_dsw = depth;
-	if (depth > 20) *(long*)0 = 0; /* ZAP! */
+	if (depth > 20) abort(); /* ZAP! */
 	while (current && !(current->flags & DSW_MARKER)) {
 		current->flags |= DSW_MARKER;
 		if (!STRING(current))
