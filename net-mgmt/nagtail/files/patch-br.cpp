--- br.cpp.orig	2011-06-01 07:28:11.000000000 -0400
+++ br.cpp	2011-06-01 07:28:49.000000000 -0400
@@ -251,10 +251,10 @@
 	return out;
 }
 
-off64_t buffered_reader::file_offset(void)
+off_t buffered_reader::file_offset(void)
 {
 	if (mmap_addr)
 		return cur_offset - mmap_addr;
 	else
-		return lseek64(fd, 0, SEEK_CUR);
+		return lseek(fd, 0, SEEK_CUR);
 }
