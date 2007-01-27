--- src/gui/wxMDialogs.cpp.orig	Sun Aug  6 22:02:01 2006
+++ src/gui/wxMDialogs.cpp	Sun Jan 28 00:15:19 2007
@@ -42,6 +42,10 @@
 #  include <wx/msgdlg.h>
 #  include <wx/choicdlg.h>
 #  include <wx/filedlg.h>
+
+#  include <wx/dcclient.h>
+#  include <wx/settings.h>
+#  include <wx/timer.h>
 #endif // USE_PCH
 
 #include "Mpers.h"
