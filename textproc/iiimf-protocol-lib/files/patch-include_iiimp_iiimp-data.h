--- include/iiimp/iiimp-data.h.orig	Wed Apr 21 16:01:34 2004
+++ include/iiimp/iiimp-data.h	Wed Apr 21 16:01:45 2004
@@ -7,11 +7,8 @@
 #include <stdio.h>
 #include <sys/types.h>
 
-#if defined(linux)
-#include <stdint.h>
 typedef unsigned char	uchar_t;
 typedef unsigned int	uint_t;
-#endif /* linux */
 
 #include <iiimp-opcode.h>
 
