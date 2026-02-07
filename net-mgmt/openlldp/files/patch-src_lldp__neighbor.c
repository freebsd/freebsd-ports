--- src/lldp_neighbor.c.orig	2010-06-08 05:06:29 UTC
+++ src/lldp_neighbor.c
@@ -30,6 +30,13 @@
 #include "tlv/tlv_common.h"
 #include "tlv/tlv.h"
 
+char lldp_systemname[512];
+char lldp_systemdesc[512];
+int neighbor_local_sd;
+int neighbor_remote_sd;
+struct sockaddr_un local;
+struct sockaddr_un remote;
+
 int get_sys_desc() {
 #ifndef WIN32
     int retval;
