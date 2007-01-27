--- src/gui/wxDialogLayout.cpp.orig	Tue Jun 27 02:31:06 2006
+++ src/gui/wxDialogLayout.cpp	Sat Jan 27 14:39:56 2007
@@ -37,6 +37,9 @@
 #  include <wx/stattext.h>
 #  include <wx/statbox.h>
 #  include <wx/statbmp.h>
+
+#  include <wx/dcclient.h>
+#  include <wx/settings.h>
 #endif // USE_PCH
 
 #include <wx/imaglist.h>
