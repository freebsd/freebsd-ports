$FreeBSD$

--- squashfs-tools/unsquashfs.c.orig	2009-04-05 23:23:06.000000000 +0200
+++ squashfs-tools/unsquashfs.c	2010-04-29 17:48:22.000000000 +0200
@@ -26,6 +26,10 @@
 #include "squashfs_compat.h"
 #include "read_fs.h"
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 struct cache *fragment_cache, *data_cache;
 struct queue *to_reader, *to_deflate, *to_writer, *from_writer;
 pthread_t *thread, *deflator_thread;
