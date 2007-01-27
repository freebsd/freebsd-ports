--- src/gui/wxFolderView.cpp.orig	Fri Jun 30 13:08:18 2006
+++ src/gui/wxFolderView.cpp	Sat Jan 27 16:14:15 2007
@@ -46,6 +46,8 @@
 
 #  include <wx/sizer.h>
 #  include <wx/accel.h>
+
+#  include <wx/timer.h>
 #endif // USE_PCH
 
 #include <ctype.h>
