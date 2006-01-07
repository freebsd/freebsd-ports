--- libk9copy/k9dvdbackup.h.orig       Thu Jan  5 06:16:05 2006
+++ libk9copy/k9dvdbackup.h    Thu Jan  5 06:16:20 2006
@@ -26,7 +26,11 @@
 #include <qobjectlist.h>
 #include "k9cell.h"
 #include <dvdread/ifo_types.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif
 #include "k9cellcopylist.h"
 /**
 @author Jean-Michel Petit
