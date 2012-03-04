--- dma.h.orig	2012-01-03 13:54:05.000000000 +0000
+++ dma.h	2012-01-28 11:02:57.000000000 +0000
@@ -74,8 +75,12 @@
 #error Please define LIBEXEC_PATH
 #endif
 
+#ifndef DMA_ROOT_USER
 #define DMA_ROOT_USER	"mail"
+#endif
+#ifndef DMA_GROUP
 #define DMA_GROUP	"mail"
+#endif
 
 #ifndef MBOX_STRICT
 #define MBOX_STRICT	0
