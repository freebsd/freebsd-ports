--- src/gui/wxSortDialog.cpp.orig	Mon Jan 24 19:36:22 2005
+++ src/gui/wxSortDialog.cpp	Sun Jan 28 00:18:38 2007
@@ -28,9 +28,8 @@
    #include <wx/layout.h>
    #include <wx/stattext.h>     // for wxStaticText
    #include <wx/statbox.h>
-#ifdef OS_WIN // cygwin and mingw
+   #include <wx/dcclient.h>
    #include <wx/settings.h>
-#endif
 #endif // USE_PCH
 
 #include "gui/wxDialogLayout.h"
