--- libdpe/common.h.orig	2014-10-24 21:51:06.000000000 +0200
+++ libdpe/common.h	2015-01-16 10:23:58.000000000 +0100
@@ -23,11 +23,11 @@
 #include <sys/mman.h>
 
 #define pwrite_retry(fd, buf,  len, off) \
-	TEMP_FAILURE_RETRY (pwrite (fd, buf, len, off))
+	pwrite (fd, buf, len, off)
 #define write_retry(fd, buf, n) \
-	TEMP_FAILURE_RETRY (write (fd, buf, n))
+	write (fd, buf, n)
 #define pread_retry(fd, buf,  len, off) \
-	TEMP_FAILURE_RETRY (pread (fd, buf, len, off))
+	pread (fd, buf, len, off)
 
 #define is_64_bit(pe) ((pe)->flags & IMAGE_FILE_32BIT_MACHINE)
 
