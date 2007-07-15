--- src/backend/back_bsd.c	2007-07-07 09:39:58.000000000 +0300
+++ src/backend/back_bsd.c_new	2007-07-07 09:39:15.000000000 +0300
@@ -51,6 +51,7 @@
 
 static void *map_dev_mem (int fd, unsigned long Base, unsigned long Size);
 static void unmap_dev_mem (unsigned long Base, unsigned long Size);
+static int probe_devices();
 
 int init_nvclock()
 {
