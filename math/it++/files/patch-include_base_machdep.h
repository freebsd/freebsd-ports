--- include/base/machdep.h.orig	Sat Feb 19 17:57:11 2005
+++ include/base/machdep.h	Sat Feb 19 17:57:22 2005
@@ -24,6 +24,7 @@
 #ifndef __machdep_h
 #define __machdep_h
 
+#include <machine/endian.h>
 #include "itconfig.h"
 
 namespace itpp {
@@ -71,9 +72,9 @@ namespace itpp {
   inline void  little_endian(it_s8 x, it_s8 &y) { y = x; }
   inline void  little_endian(it_u8 x, it_u8 &y) { y = x; }
 
-#if defined(sparc)
+#if _BYTE_ORDER == _LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__
-#elif defined(i386) || defined(_M_IX86) || defined(alpha) || defined(vms)
+#elif _BYTE_ORDER == _BIG_ENDIAN
 #define __BIG_ENDIAN__
 #endif
 
