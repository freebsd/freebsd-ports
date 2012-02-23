Index: freebsd/include/stdbool.h
===================================================================
--- freebsd/include/stdbool.h.orig	(revision 10467)
+++ freebsd/include/stdbool.h	(revision 10468)
@@ -1,11 +1,15 @@
 #ifndef _STDBOOL_H_
 #define _STDBOOL_H_
 
+#include <sys/types.h>
+
+#ifndef __bool_true_false_are_defined
 typedef int bool;
 
 enum {
 	false,
 	true
 };
+#endif
 
 #endif /* _STDBOOL_H_ */
