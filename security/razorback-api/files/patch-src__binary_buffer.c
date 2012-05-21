--- ./src/binary_buffer.c.orig	2012-01-05 17:40:55.000000000 -0500
+++ ./src/binary_buffer.c	2012-05-09 18:16:59.000000000 -0400
@@ -28,6 +28,20 @@
 
 #include <stdio.h>
 
+#include <osreldate.h>
+#if __FreeBSD_version < 800067
+size_t strnlen(const char *s, size_t maxlen);
+size_t strnlen(const char *s, size_t maxlen)
+{
+	size_t i;
+	for (i = 0; i < maxlen; i++) {
+		if (s[i] == '\0')
+			break;
+	}
+	return i;
+}
+#endif
+
 struct BinaryBuffer *
 BinaryBuffer_CreateFromMessage (struct Message *message)
 {
