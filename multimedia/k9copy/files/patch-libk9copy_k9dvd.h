--- libk9copy/k9dvd.h.orig     Thu Jan  5 06:13:32 2006
+++ libk9copy/k9dvd.h  Thu Jan  5 06:13:58 2006
@@ -25,7 +25,11 @@
 #include <qobjectlist.h>
 #include <qdatetime.h>
 #include <qvaluelist.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif
 #include <dvdread/ifo_types.h>


