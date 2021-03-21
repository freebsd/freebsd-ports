--- mksquashfs.c.orig	2019-08-29 01:58:04 UTC
+++ mksquashfs.c
@@ -35,7 +35,6 @@
 #include <stddef.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/sysmacros.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <dirent.h>
@@ -50,7 +49,6 @@
 #include <sys/wait.h>
 #include <limits.h>
 #include <ctype.h>
-#include <sys/sysinfo.h>
 
 #ifndef linux
 #define __BYTE_ORDER BYTE_ORDER
@@ -5195,6 +5193,7 @@ int get_physical_memory()
 	long long page_size = sysconf(_SC_PAGESIZE);
 	int phys_mem;
 
+#ifdef __linux__
 	if(num_pages == -1 || page_size == -1) {
 		struct sysinfo sys;
 		int res = sysinfo(&sys);
@@ -5205,6 +5204,7 @@ int get_physical_memory()
 		num_pages = sys.totalram;
 		page_size = sys.mem_unit;
 	}
+#endif
 
 	phys_mem = num_pages * page_size >> 20;
 
