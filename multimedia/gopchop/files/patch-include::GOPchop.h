--- include/GOPchop.h.orig	Sun Apr 27 13:13:19 2003
+++ include/GOPchop.h	Sun Jun  8 16:59:13 2003
@@ -31,7 +31,13 @@
 #endif
 
 /* get the cool numbers */
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+# include <stdint.h>
+#endif
+
+#ifdef HAVE_INTTYPES_H
+# include <inttypes.h>
+#endif
 
 /* import locale functions */
 #include "gettext.h"
@@ -50,7 +56,7 @@
 #endif
 
 /* figure out off_t formatting */
-#if _FILE_OFFSET_BITS==64
+#if _FILE_OFFSET_BITS==64 || defined(__FreeBSD__)
 # define OFF_T_FORMAT  "llu"
 #else
 # warning "Not compiling for large file (>2G) support!"
