--- gst/cothreads.c.orig	Sat Feb  1 19:09:00 2003
+++ gst/cothreads.c	Mon Feb  3 10:57:44 2003
@@ -41,12 +41,16 @@
 #include <ucontext.h>
 #endif
 
+#ifdef HAVE_MAKECONTEXT
+#include <ucontext.h>
+#endif
+
 /* older glibc's have MAP_ANON instead of MAP_ANONYMOUS */
 #ifndef MAP_ANONYMOUS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#define STACK_SIZE 0x200000
+#define STACK_SIZE 0x100000
 
 #define COTHREAD_MAGIC_NUMBER 0xabcdef
 
