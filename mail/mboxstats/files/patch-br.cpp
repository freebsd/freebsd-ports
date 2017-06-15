--- br.cpp.orig	2008-12-22 06:59:59 UTC
+++ br.cpp
@@ -160,6 +160,16 @@ int buffered_reader::read_into_buffer(vo
 	return n_read;
 }
 
+char *strndup(char *in, int size)
+{
+        char *out = (char *)malloc(size + 1);
+
+        memcpy(out, in, size);
+        out[size] = 0x00;
+
+        return out;
+}
+
 char * buffered_reader::read_line(void)
 {
 	char *out = NULL;
