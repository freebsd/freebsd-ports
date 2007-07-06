--- br.h.orig	Mon Nov 27 06:21:58 2006
+++ br.h	Sat Apr 28 13:45:23 2007
@@ -16,6 +16,8 @@
  *
  */
 
+#include <sys/types.h>
+
 /* code taken from linux kernel */
 #if __GNUC__ == 2 && __GNUC_MINOR__ < 96
 #define __builtin_expect(x, expected_value) (x)
@@ -33,7 +35,7 @@
         char *buffer;
         long long int buffer_length, buffer_pointer;
 	char *mmap_addr, *cur_offset;
-	off64_t size_of_file;
+	off_t size_of_file;
 
         int number_of_bytes_in_buffer(void);
         int read_into_buffer(void);
@@ -46,5 +48,5 @@
 
         char * read_line(void);
 
-	off64_t file_offset(void);
+	off_t file_offset(void);
 };
