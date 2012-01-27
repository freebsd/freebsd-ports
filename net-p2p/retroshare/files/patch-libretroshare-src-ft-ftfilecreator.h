--- libretroshare/src/ft/ftfilecreator.h~	2011-04-25 16:20:57.000000000 +0200
+++ libretroshare/src/ft/ftfilecreator.h	2012-01-15 20:30:41.000000000 +0100
@@ -35,6 +35,7 @@
 #include "ftfileprovider.h"
 #include "ftchunkmap.h"
 #include <map>
+#define fseeko64 fseeko
 
 class ZeroInitCounter
 {
