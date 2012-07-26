--- mozilla/widget/src/qt/nsWindow.cpp~
+++ mozilla/widget/src/qt/nsWindow.cpp
@@ -43,6 +43,7 @@ using namespace QtMobility;
 
 #ifdef MOZ_X11
 #include <X11/Xlib.h>
+#include "mozilla/X11Util.h"
 #endif //MOZ_X11
 
 #include "nsXULAppAPI.h"
