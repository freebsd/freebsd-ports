--- src/tree.c.orig	2016-11-19 19:41:38 UTC
+++ src/tree.c
@@ -37,6 +37,8 @@ extern tcpprep_t *tcpprep;
 extern int debug;
 #endif
 
+#include <sys/socket.h>
+
 /* static buffer used by tree_print*() functions */
 char tree_print_buff[TREEPRINTBUFFLEN]; 
 
