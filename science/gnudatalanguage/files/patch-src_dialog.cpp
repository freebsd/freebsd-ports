--- src/dialog.cpp.orig	2017-05-31 19:49:13 UTC
+++ src/dialog.cpp
@@ -18,8 +18,9 @@
 #include "includefirst.hpp"
 
 #ifdef HAVE_LIBWXWIDGETS
-#include <wx/filedlg.h>
-#include <wx/msgdlg.h>
+//following includes are 1) not necessary and 2) create a problem with gcc6
+//#include <wx/filedlg.h>
+//#include <wx/msgdlg.h>
 #endif
 
 #include "envt.hpp"
