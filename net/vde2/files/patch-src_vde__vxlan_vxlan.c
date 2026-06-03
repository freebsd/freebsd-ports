--- src/vde_vxlan/vxlan.c.orig	2026-03-23 08:45:44 UTC
+++ src/vde_vxlan/vxlan.c
@@ -24,6 +24,7 @@
 
 #include <netinet/in.h>
 #include <sys/un.h>
+#include <sys/socket.h>
 
 #include "vxlan_hash.h"
 #include "log.h"
