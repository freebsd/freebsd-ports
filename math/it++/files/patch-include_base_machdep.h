--- include/base/machdep.h.orig	2005-01-17 09:02:20.000000000 +0000
+++ include/base/machdep.h	2008-04-30 11:49:04.000000000 +0000
@@ -24,6 +24,7 @@
 #ifndef __machdep_h
 #define __machdep_h
 
+#include <machine/endian.h>
 #include "itconfig.h"
 
 namespace itpp {
@@ -71,9 +72,9 @@
   inline void  little_endian(it_s8 x, it_s8 &y) { y = x; }
   inline void  little_endian(it_u8 x, it_u8 &y) { y = x; }
 
-#if defined(sparc)
+#if _BYTE_ORDER == _LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__
-#elif defined(i386) || defined(_M_IX86) || defined(_x86_64) || defined(alpha) || defined(vms)
+#elif _BYTE_ORDER == _BIG_ENDIAN
 #define __BIG_ENDIAN__
 #endif
 
