--- br.h.orig	2011-06-01 07:45:29.000000000 -0400
+++ br.h	2011-06-01 07:45:38.000000000 -0400
@@ -33,7 +33,7 @@
         char *buffer;
         long long int buffer_length, buffer_pointer;
 	char *mmap_addr, *cur_offset;
-	off64_t size_of_file;
+	off_t size_of_file;
 
         int number_of_bytes_in_buffer(void);
         int read_into_buffer(void);
@@ -46,5 +46,5 @@
 
         char * read_line(void);
 
-	off64_t file_offset(void);
+	off_t file_offset(void);
 };
