--- types.h.orig	Sun Mar 25 21:29:19 2001
+++ types.h	Sun Mar 25 21:29:29 2001
@@ -4,7 +4,7 @@
 /********************************************************************
  * Elementary data types
  ********************************************************************/
-#include <endian.h>
+#include <machine/endian.h>
 
 #define CPU_ENDIAN_LITTLE	__LITTLE_ENDIAN
 #define CPU_ENDIAN_BIG		__BIG_ENDIAN
