--- iiimxcf/xiiimp.so/iiimp/iiimpAux.c	Sat Sep 11 01:41:45 2004
+++ iiimxcf/xiiimp.so/iiimp/iiimpAux.c	Wed Feb 16 20:40:57 2005
@@ -80,7 +80,7 @@
 #include "trace_message.h"
 
 
-#define AUX_BASE_DIR		"/usr/lib/im/"
+#define AUX_BASE_DIR		IMDIR
 
 #if defined(__sparcv9)
 #define SPARCV9_DIR		"sparcv9/"
