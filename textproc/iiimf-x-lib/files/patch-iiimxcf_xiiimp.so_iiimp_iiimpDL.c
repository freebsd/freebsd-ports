--- iiimxcf/xiiimp.so/iiimp/iiimpDL.c	Wed May  5 03:55:05 2004
+++ iiimxcf/xiiimp.so/iiimp/iiimpDL.c	Wed Feb 16 20:41:14 2005
@@ -108,7 +108,7 @@
 }
 
 #ifndef XLOCALEDIR
-#define XLOCALEDIR "/usr/lib/im/modules"
+#define XLOCALEDIR (IMDIR "/modules")
 #endif
 
 static const char*
