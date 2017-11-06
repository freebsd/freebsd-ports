--- spunk/machine.h.orig	1997-02-18 13:41:50 UTC
+++ spunk/machine.h
@@ -238,7 +238,7 @@ typedef unsigned        u32;            
 #    define CPU_LITTLE_ENDIAN
 #elif (BYTE_ORDER == BIG_ENDIAN)
 #    define CPU_BIG_ENDIAN
-#elif
+#else
 #    error Byte order not defined!
 #endif
 
