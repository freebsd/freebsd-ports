--- src/acl/external/eDirectory_userip/ext_edirectory_userip_acl.cc.orig	2020-04-19 12:38:51 UTC
+++ src/acl/external/eDirectory_userip/ext_edirectory_userip_acl.cc
@@ -69,6 +69,12 @@
 #ifdef HAVE_NETDB_H
 #include <netdb.h>
 #endif
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+#ifdef HAVE_NETINET_IN_H
+#include <netinet/in.h>
+#endif
 
 #ifdef HELPER_INPUT_BUFFER
 #define EDUI_MAXLEN     HELPER_INPUT_BUFFER
