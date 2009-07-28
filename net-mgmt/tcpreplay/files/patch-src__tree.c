--- ./src/tree.c.orig	2009-07-28 09:16:43.000000000 +0200
+++ ./src/tree.c	2009-07-28 09:16:57.000000000 +0200
@@ -48,6 +48,8 @@
 extern int debug;
 #endif
 
+#include <sys/socket.h>
+
 /* static buffer used by tree_print*() functions */
 char tree_print_buff[TREEPRINTBUFFLEN]; 
 
