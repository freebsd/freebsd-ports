--- compat/compat.h.orig	2013-11-30 13:55:13 UTC
+++ compat/compat.h
@@ -104,10 +104,12 @@
  */
 #include "compat/GnuRegex.h"
 
-/* some functions are unsafe to be used in Squid. */
-#include "compat/unsafe.h"
-
 /* cppunit is not quite C++0x compatible yet */
 #include "compat/cppunit.h"
 
+/* some functions are unsafe to be used in Squid. */
+/* XXX MBi do this only after including cppunit.h as that itself also
+   uses printf() */
+#include "compat/unsafe.h"
+
 #endif /* _SQUID_COMPAT_H */
