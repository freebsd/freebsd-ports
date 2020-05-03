--- src/acl/external/eDirectory_userip/ext_edirectory_userip_acl.cc.orig	2020-04-19 12:38:51 UTC
+++ src/acl/external/eDirectory_userip/ext_edirectory_userip_acl.cc
@@ -69,6 +69,9 @@
 #ifdef HAVE_NETDB_H
 #include <netdb.h>
 #endif
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #ifdef HELPER_INPUT_BUFFER
 #define EDUI_MAXLEN     HELPER_INPUT_BUFFER
