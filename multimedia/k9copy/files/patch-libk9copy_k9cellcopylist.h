--- libk9copy/k9cellcopylist.h.orig    Thu Jan  5 06:10:57 2006
+++ libk9copy/k9cellcopylist.h Thu Jan  5 06:11:13 2006
@@ -24,7 +24,11 @@
 #include "k9dvd.h"
 #include "k9cell.h"
 #include <dvdread/ifo_types.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif

 class k9CellCopyVTS {
 private:
