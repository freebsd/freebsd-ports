--- iiimxcf/xiiimp.so/iiimp/csconv.h	Fri Mar 16 00:52:22 2001
+++ iiimxcf/xiiimp.so/iiimp/csconv.h	Wed Feb 16 20:48:14 2005
@@ -64,7 +64,7 @@
 #    define	CSC_BASE_DIR_SYSTEM	"/etc/lib/im/csconv/"
 #endif /* !CSC_BASE_DIR_SYSTEM */
 #if !defined(CSC_BASE_DIR_DEFAULT)
-#    define	CSC_BASE_DIR_DEFAULT	"/usr/lib/im/csconv/"
+#    define	CSC_BASE_DIR_DEFAULT	(IMDIR "/csconv/")
 #endif /* !CSC_BASE_DIR_DEFAULT */
 
 #define CSC_IS_PATH_ABS(path)	(('/' == *(path)) ||			\
