--- iiimxcf/htt_xbe/lib/IMdkit/common/XIMPublic.cpp	Wed Mar 24 04:54:26 2004
+++ iiimxcf/htt_xbe/lib/IMdkit/common/XIMPublic.cpp	Wed Feb 16 21:31:00 2005
@@ -68,7 +68,7 @@
 #ifdef sun
 #define XIIIMP_PATH     "/usr/openwin/lib/locale/common/xiiimp.so.2"
 #else /* Linux */
-#define XIIIMP_PATH     "/usr/lib/im/xiiimp.so.2"
+#define XIIIMP_PATH     (IMDIR "/xiiimp.so.2")
 #endif /* Linux */
 
 #include <stdio.h>
