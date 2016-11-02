--- src/plugins/node_features/knl_generic/node_features_knl_generic.c.orig	2016-11-01 15:40:01 UTC
+++ src/plugins/node_features/knl_generic/node_features_knl_generic.c
@@ -46,6 +46,10 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define POLLRDHUP POLLHUP
+#endif
+
 #include "slurm/slurm.h"
 
 #include "src/common/assoc_mgr.h"
