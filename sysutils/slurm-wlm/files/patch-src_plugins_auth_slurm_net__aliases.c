--- src/plugins/auth/slurm/net_aliases.c.orig	2023-12-13 21:49:39 UTC
+++ src/plugins/auth/slurm/net_aliases.c
@@ -40,6 +40,10 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#include <sys/socket.h>
+#endif
 
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
