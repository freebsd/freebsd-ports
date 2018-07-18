--- clib/stack.c.orig	2018-07-18 19:43:55 UTC
+++ clib/stack.c
@@ -11,6 +11,9 @@
 
 #if !defined(__WIN32)
 #include <sys/resource.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#endif
 
 void remove_stack_limit_(void) {
  
