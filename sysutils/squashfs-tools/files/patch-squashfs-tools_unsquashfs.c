$FreeBSD$

--- unsquashfs.c.orig	2010-09-20 03:14:38.000000000 +0530
+++ unsquashfs.c	2010-09-29 09:34:43.000000000 +0530
@@ -29,9 +29,16 @@
 #include "compressor.h"
 #include "xattr.h"
 
+#ifdef __linux__
 #include <sys/sysinfo.h>
+#endif
+
 #include <sys/types.h>
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 struct cache *fragment_cache, *data_cache;
 struct queue *to_reader, *to_deflate, *to_writer, *from_writer;
 pthread_t *thread, *deflator_thread;
