--- dcfldd.h.orig	Sun May 15 08:06:08 2005
+++ dcfldd.h	Sat Jul  2 23:09:19 2005
@@ -92,6 +92,8 @@
 /* Use separate input and output buffers, and combine partial input blocks. */
 #define C_TWOBUFS 04000
 
+#define uintmax_t uint64_t
+
 extern char *program_name;
 
 extern char *input_file;
