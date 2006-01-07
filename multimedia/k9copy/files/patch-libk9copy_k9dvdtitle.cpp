--- libk9copy/k9dvdtitle.cpp.orig      Thu Jan  5 06:16:57 2006
+++ libk9copy/k9dvdtitle.cpp   Thu Jan  5 06:17:14 2006
@@ -31,7 +31,11 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <qvaluelist.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif


 //*******************k9DVDAudioStream**************
