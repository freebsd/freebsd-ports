--- libretroshare/src/ft/ftfileprovider.h~	2011-02-20 01:59:47.000000000 +0100
+++ libretroshare/src/ft/ftfileprovider.h	2012-01-15 04:01:35.000000000 +0100
@@ -34,6 +34,7 @@
 #include <stdint.h>
 #include "util/rsthreads.h"
 #include "retroshare/rsfiles.h"
+#define fseeko64 fseeko
 
 class ftFileProvider
 {
