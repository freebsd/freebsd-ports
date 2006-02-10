--- lib/buffer.c.orig	Fri Feb  3 13:24:03 2006
+++ lib/buffer.c	Fri Feb  3 13:24:15 2006
@@ -53,7 +53,7 @@
   size_t sp;
 
   /* Actual data stream (variable length). */
-  unsigned char data[];  /* real dimension is buffer->size */
+  unsigned char data[0];  /* real dimension is buffer->size */
 };
 
 /* It should always be true that: 0 <= sp <= cp <= size */
