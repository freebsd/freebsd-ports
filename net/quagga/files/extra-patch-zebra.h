Index: lib/zebra.h
===================================================================
RCS file: /var/cvsroot/quagga/lib/zebra.h,v
retrieving revision 1.27
diff -u -b -r1.27 zebra.h
--- lib/zebra.h	4 Jan 2005 16:24:43 -0000	1.27
+++ lib/zebra.h	10 Jan 2005 15:35:47 -0000
@@ -97,9 +97,17 @@
 #include <stdarg.h>
 #if !(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
 /* Not C99; do we need to define va_copy? */
-#if !defined(va_copy) && defined(__va_copy)
+#ifndef va_copy
+#ifdef __va_copy
 #define va_copy(DST,SRC) __va_copy(DST,SRC)
-#endif /* need va_copy */
+#else
+/* Now we are desperate; this should work on many typical platforms. 
+   But this is slightly dangerous, because the standard does not require
+   va_copy to be a macro. */
+#define va_copy(DST,SRC) (DST) = (SRC)
+#warning "Not C99 and no va_copy macro available, using simple assignment..."
+#endif /* __va_copy */
+#endif /* !va_copy */
 #endif /* !C99 */
 #include "zassert.h"
 
