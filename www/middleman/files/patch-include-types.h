--- include/types.h.orig	Sat Nov  5 19:51:41 2005
+++ include/types.h	Sat Nov  5 19:51:54 2005
@@ -1,6 +1,8 @@
 #ifndef TYPES_H
 #define TYPES_H
 
+#include <sys/types.h>
+
 struct unlink_list {
 	struct unlink_list *next;
 	char *path;
