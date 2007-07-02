--- br.cpp.orig	Tue Jun 19 17:54:16 2007
+++ br.cpp	Tue Jun 19 17:55:30 2007
@@ -160,6 +160,16 @@
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
