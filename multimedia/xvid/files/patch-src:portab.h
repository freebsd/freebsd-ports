--- ../../src/portab.h.orig	Sat Nov 23 22:50:14 2002
+++ ../../src/portab.h	Fri Jan  3 14:40:18 2003
@@ -83,6 +83,14 @@
  *  Types used in XviD sources
  ****************************************************************************/
 
+#if defined(HAVE_SYS_PARAM_H)
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000 && defined(HAVE_SYS_ENDIAN_H)
+#include <sys/endian.h>
+#endif
+
 /*----------------------------------------------------------------------------
  | Standard Unix include file (sorry, we put all unix into "linux" case)
  *---------------------------------------------------------------------------*/
@@ -90,8 +98,15 @@
 #if defined(LINUX) || defined(BEOS) || defined(FREEBSD)
 
 /* All (u)int(size)_t types are defined here */
-#    include <inttypes.h>
 
+#include "../../config.h"
+
+#if defined(HAVE_STDINT_H)
+#include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
+	
 /*----------------------------------------------------------------------------
  | msvc (lacks such a header file)
  *---------------------------------------------------------------------------*/
@@ -139,6 +154,9 @@
 #elif defined(ARCH_IA64)
 #    define CACHE_LINE  32
 #    define ptr_t uint64_t
+#elif defined(__FreeBSD__)
+#    define CACHE_LINE  (SIZEOF_UINTPTR_T * 4)
+#    define ptr_t uintptr_t
 #else
 #    error Architecture not supported.
 #endif
@@ -341,6 +359,13 @@
          {
              return 0;
          }
+
+/*----------------------------------------------------------------------------
+ | FreeBSD specific macros/functions
+ *---------------------------------------------------------------------------*/
+#    elif defined(__FreeBSD__) && __FreeBSD_version >= 470000 && defined(HAVE_SYS_ENDIAN_H)
+#	define BSWAP(a) (be32toh(x))
+#	error Missing EMMS() definition for this architecture.
 
 /*----------------------------------------------------------------------------
  | XviD + gcc unsupported Architecture
