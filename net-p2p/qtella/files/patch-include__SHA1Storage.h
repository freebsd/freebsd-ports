--- include/SHA1Storage.h.orig	Fri May 21 01:14:16 2004
+++ include/SHA1Storage.h	Mon Jan 29 22:00:47 2007
@@ -7,7 +7,11 @@
 #include <qobject.h>
 #include <qstring.h>
 #include <qtimer.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <inttypes.h>
+#endif
 
 #include "SharedFile.h"
 
