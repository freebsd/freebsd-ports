--- src/lldp_neighbor.h.orig	2010-06-08 05:06:29 UTC
+++ src/lldp_neighbor.h
@@ -19,17 +19,17 @@
 
 #include "lldp_port.h"
 
-char lldp_systemname[512];
-char lldp_systemdesc[512];
+extern char lldp_systemname[512];
+extern char lldp_systemdesc[512];
 
-int neighbor_local_sd;
-int neighbor_remote_sd;
+extern int neighbor_local_sd;
+extern int neighbor_remote_sd;
 
 #ifdef WIN32
 // Need to define this
 #else
-struct sockaddr_un local;
-struct sockaddr_un remote;
+extern struct sockaddr_un local;
+extern struct sockaddr_un remote;
 #endif
 
 int get_sys_desc(void);
