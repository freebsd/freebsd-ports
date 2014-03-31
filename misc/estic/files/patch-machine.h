--- spunk/machine.h.orig	1997-02-18 14:41:50.000000000 +0100
+++ spunk/machine.h	2014-03-28 16:58:13.000000000 +0100
@@ -238,7 +238,7 @@
 #    define CPU_LITTLE_ENDIAN
 #elif (BYTE_ORDER == BIG_ENDIAN)
 #    define CPU_BIG_ENDIAN
-#elif
+#else
 #    error Byte order not defined!
 #endif
 
