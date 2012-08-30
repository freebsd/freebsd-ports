--- toolkit/xre/nsEmbedFunctions.cpp~
+++ toolkit/xre/nsEmbedFunctions.cpp
@@ -36,6 +36,7 @@
  * ***** END LICENSE BLOCK ***** */
 
 #if defined(MOZ_WIDGET_QT)
+#include <unistd.h>
 #include "nsQAppInstance.h"
 #endif
 
