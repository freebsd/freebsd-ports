--- include/GOPchop.h.orig	Sun Apr 27 13:13:19 2003
+++ include/GOPchop.h	Tue Apr  6 19:31:08 2004
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
@@ -50,11 +56,15 @@
 #endif
 
 /* figure out off_t formatting */
+#if defined(__FreeBSD__)
+# define OFF_T_FORMAT  "llu"
+#else
 #if _FILE_OFFSET_BITS==64
 # define OFF_T_FORMAT  "llu"
 #else
 # warning "Not compiling for large file (>2G) support!"
 # define OFF_T_FORMAT  "lu"
+#endif
 #endif
 
 /* define a string length used for short reports */
