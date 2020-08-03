--- sadmin/xfs_irecover.c.orig	2020-07-12 09:44:16 UTC
+++ sadmin/xfs_irecover.c
@@ -42,7 +42,7 @@
 #include <libHX/proc.h>
 #include <libHX/string.h>
 #include <arpa/inet.h>
-#include <linux/types.h>
+#include <infiniband/types.h>
 
 struct work_info {
 	char *device;
