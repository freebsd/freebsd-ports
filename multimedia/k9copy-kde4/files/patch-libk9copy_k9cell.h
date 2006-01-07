--- libk9copy/k9cell.h.orig    Thu Jan  5 06:09:52 2006
+++ libk9copy/k9cell.h Thu Jan  5 06:10:12 2006
@@ -22,7 +22,11 @@

 #include <qobject.h>
 #include <qobjectlist.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif
 #include "k9dvdtitle.h"
 enum streamType_t {stAudio,stVideo,stSubpicture,stOther};
 /**
