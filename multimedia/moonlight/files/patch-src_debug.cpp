--- src/debug.cpp.orig	2009-01-13 19:41:33.000000000 +0000
+++ src/debug.cpp	2009-02-12 17:50:56.000000000 +0000
@@ -120,6 +120,19 @@
 
 static Addr2LineData *addr2line_pipes = NULL;
 
+#ifndef getline
+gint64
+getline(char **buffer, size_t *len, FILE *stream)
+{
+	*buffer = (char *)calloc(1, 512); /* Should be plenty */
+
+	if (fgets(*buffer, 512, stream) == NULL)
+		return -1;
+	*len = strlen(*buffer);
+	return *len;
+}
+#endif
+
 static char*
 library_of_ip (gpointer ip, gpointer* base_address)
 {
