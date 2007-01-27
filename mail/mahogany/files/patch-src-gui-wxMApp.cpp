--- src/gui/wxMApp.cpp.orig	Wed Apr 19 02:55:04 2006
+++ src/gui/wxMApp.cpp	Sun Jan 28 00:11:27 2007
@@ -34,6 +34,8 @@
 #  include <wx/msgdlg.h>   // for wxMessageBox
 #  include <wx/menu.h>
 #  include <wx/statusbr.h>
+
+#  include <wx/timer.h>
 #endif // USE_PCH
 
 #include "wx/persctrl.h" // for wxPMessageBoxEnable
