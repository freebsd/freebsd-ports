--- gst/cothreads.c.orig	Wed Nov 13 22:59:21 2002
+++ gst/cothreads.c	Wed Nov 13 22:59:38 2002
@@ -41,11 +41,11 @@
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#define STACK_SIZE 0x200000
+#define STACK_SIZE 0x100000
 
 #define COTHREAD_MAGIC_NUMBER 0xabcdef
 
-#define COTHREAD_MAXTHREADS 16
+#define COTHREAD_MAXTHREADS 8
 #define COTHREAD_STACKSIZE (STACK_SIZE/COTHREAD_MAXTHREADS)
 
 static void 	cothread_destroy 	(cothread_state *thread);
