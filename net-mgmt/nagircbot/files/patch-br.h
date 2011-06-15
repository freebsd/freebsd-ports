--- br.h.orig	2011-01-18 05:39:10.000000000 -0500
+++ br.h	2011-05-31 22:12:14.000000000 -0400
@@ -1,5 +1,7 @@
 /* (C) 2006-2010 by folkert@vanheusden.com GPLv2 applies */
 
+#include <sys/types.h>
+
 /* code taken from linux kernel */
 #if __GNUC__ == 2 && __GNUC_MINOR__ < 96
 #define __builtin_expect(x, expected_value) (x)
@@ -17,7 +19,7 @@
         char *buffer;
         long long int buffer_length, buffer_pointer;
 	char *mmap_addr, *cur_offset;
-	off64_t size_of_file;
+	off_t size_of_file;
 
         int number_of_bytes_in_buffer(void);
         int read_into_buffer(void);
@@ -30,5 +32,5 @@
 
         char * read_line(void);
 
-	off64_t file_offset(void);
+	off_t file_offset(void);
 };
