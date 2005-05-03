--- gst/cothreads.c.orig	Tue May  3 16:17:09 2005
+++ gst/cothreads.c	Tue May  3 16:17:23 2005
@@ -56,7 +56,7 @@
 #endif
 #endif
 
-#define STACK_SIZE 0x200000
+#define STACK_SIZE 0x100000
 
 #define COTHREAD_MAGIC_NUMBER 0xabcdef
 
