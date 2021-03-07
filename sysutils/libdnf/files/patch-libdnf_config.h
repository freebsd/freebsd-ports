--- libdnf/config.h.orig	2021-03-07 20:35:58 UTC
+++ libdnf/config.h
@@ -18,7 +18,18 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
-#include <bits/wordsize.h>
+//#include <bits/wordsize.h>
+
+#include <stdint.h>
+
+#ifndef __WORDSIZE
+#  if defined(UINTPTR_MAX) && defined(UINT64_MAX) && (UINTPTR_MAX == UINT64_MAX)
+#    define __WORDSIZE 64
+#  else
+#    define __WORDSIZE 32
+#  endif
+#endif
+
 
 #if __WORDSIZE == 32
 #include "config-32.h"
