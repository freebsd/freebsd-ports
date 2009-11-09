--- src/mod_accesslog.c.orig	2009-11-05 12:40:58.000000000 -0200
+++ src/mod_accesslog.c	2009-11-05 12:41:17.000000000 -0200
@@ -162,7 +162,9 @@
 	if (str->used == 0) return;
 	buffer_prepare_append(dest, str->used - 1);
 
-	for (unsigned int i = 0; i < str->used - 1; i++) {
+	unsigned int i;
+
+	for (i = 0; i < str->used - 1; i++) {
 		if (str->ptr[i] >= ' ' && str->ptr[i] <= '~') {
 			/* printable chars */
 			buffer_append_string_len(dest, &str->ptr[i], 1);
