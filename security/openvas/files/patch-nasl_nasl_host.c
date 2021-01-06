--- nasl/nasl_host.c	2021-01-04 17:21:14.150833000 -0500
+++ nasl/nasl_host.c	2021-01-04 17:21:49.587410000 -0500
@@ -38,6 +38,8 @@
 #include "nasl_tree.h"
 #include "nasl_var.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h> /* for inet_aton */
 #include <gvm/base/networking.h>
 #include <gvm/util/kb.h>
