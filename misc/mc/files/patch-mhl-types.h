--- mhl/types.h.orig	2009-02-05 12:59:45.000000000 +0600
+++ mhl/types.h	2009-02-05 13:00:12.000000000 +0600
@@ -7,10 +7,12 @@
 #ifndef __MHL_TYPES_H
 #define __MHL_TYPES_H
 
+#ifndef __bool_true_false_are_defined
 typedef enum 
 {
     false	= 0,
     true	= 1
 } bool;
+#endif
 
 #endif
