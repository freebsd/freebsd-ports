--- widget/src/qt/nsNativeThemeQt.cpp~
+++ widget/src/qt/nsNativeThemeQt.cpp
@@ -25,7 +25,9 @@
 #include "nsThemeConstants.h"
 #include "nsIServiceManager.h"
 #include "nsIDOMHTMLInputElement.h"
+#ifdef __GLIBC__
 #include <malloc.h>
+#endif
 
 
 #include "gfxASurface.h"
