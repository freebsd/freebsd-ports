--- src/util.c.orig	Wed May 26 19:24:44 2004
+++ src/util.c	Sun May 30 17:57:02 2004
@@ -2328,9 +2328,14 @@
 static size_t
 parse_content_len(const char *data, size_t data_len)
 {
-	size_t content_len = 0;
+	int content_len = 0;
+	char *tmp;
 
-	sscanf(data, "Content-Length: %d", (int *)&content_len);
+	tmp = g_malloc(data_len + 1);
+	memcpy(tmp, data, data_len);
+	tmp[data_len] = '\0';
+	sscanf(tmp, "Content-Length: %d", &content_len);
+	g_free(tmp);
 
 	return content_len;
 }
