--- source/common/common/stack_array.h.orig	2019-04-05 18:07:44 UTC
+++ source/common/common/stack_array.h
@@ -2,9 +2,6 @@
 
 #ifdef WIN32
 #include <malloc.h>
-
-#else
-#include <alloca.h>
 #endif
 
 #include <stddef.h>
