--- br.cpp.orig	Mon Nov 27 06:21:58 2006
+++ br.cpp	Sat Apr 28 13:45:23 2007
@@ -29,11 +29,12 @@
 #include <fcntl.h>
 #include <syslog.h>
 #include "br.h"
+#include "utils.h"
 
 buffered_reader::buffered_reader(int cur_fd, int cur_block_size)
 {
 #ifdef USE_MMAP
-	struct stat64 finfo;
+	struct stat finfo;
 #endif
 
 	fd = cur_fd;
@@ -44,20 +45,20 @@
 
 	/* try do mmap */
 #ifdef USE_MMAP
-	if (fstat64(cur_fd, &finfo) == 0)
+	if (fstat(cur_fd, &finfo) == 0)
 	{
 		if (!S_ISFIFO(finfo.st_mode))
 		{
 			/* mmap */
 			size_of_file = finfo.st_size;
-			cur_offset = mmap_addr = (char *)mmap64(NULL, size_of_file, PROT_READ, MAP_SHARED, cur_fd, 0);
+			cur_offset = mmap_addr = (char *)mmap(NULL, size_of_file, PROT_READ, MAP_SHARED, cur_fd, 0);
 			if (!mmap_addr)
 			{
-				fprintf(stderr, "mmap64 failed: %d/%s\n", errno, strerror(errno));
+				fprintf(stderr, "mmap failed: %d/%s\n", errno, strerror(errno));
 			}
 
 			/* advise the kernel how to treat the mmaped region */
-			/* FIXME: change to madvise64 as soon as it comes available */
+			/* FIXME: change to madvise as soon as it comes available */
 			(void)madvise(mmap_addr, size_of_file, MADV_SEQUENTIAL);
 
 			// fprintf(stderr, "*using mmap*\n");
@@ -237,7 +238,7 @@
 
 		n_bytes = lf_offset - buffer_pointer;
 
-		out = strndup(&buffer[buffer_pointer], n_bytes);
+		out = mystrndup(&buffer[buffer_pointer], n_bytes);
 		if (!out)
 		{
 			fprintf(stderr, "buffered_reader::read_line: malloc(%lld) failed\n", n_bytes + 1);
@@ -251,10 +252,10 @@
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
