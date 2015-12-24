--- src/saga_core/saga_gui/dlg_about.cpp.orig	2015-12-21 09:38:29 UTC
+++ src/saga_core/saga_gui/dlg_about.cpp
@@ -65,6 +65,7 @@
 #include <saga_api/clipper.hpp>
 
 #include <wx/notebook.h>
+#include <wx/platform.h>
 
 #include "helper.h"
 
@@ -188,7 +189,7 @@ wxString CDLG_About::_Get_Version(void)
 	s	+= "System for Automated Geoscientific Analyses\n";
 	s	+= "http://www.saga-gis.org\n";
 	s	+= "\n";
-	s	+= "Version: " + wxString(SAGA_VERSION) + "\n";
+	s	+= "Version: " + wxString(SAGA_VERSION) + " (SVN r2737)" + "\n";
 
 #ifdef _SAGA_MSW
 	#ifdef _WIN64
@@ -264,7 +265,21 @@ wxString CDLG_About::_Get_Version(void)
 		#elif	defined(__GNUWIN32__)
 			"Gnu-Win32 compiler"
 		#elif	defined(__GNUG__)
-			"Gnu C++"
+			#if   wxCHECK_GCC_VERSION(5,1)
+				"Gnu C++ 5.1"
+			#elif   wxCHECK_GCC_VERSION(5,0)
+				"Gnu C++ 5.0"
+			#elif wxCHECK_GCC_VERSION(4,9)
+				"Gnu C++ 4.9"
+			#elif wxCHECK_GCC_VERSION(4,8)
+				"Gnu C++ 4.8"
+		#elif wxCHECK_GCC_VERSION(4,7)
+				"Gnu C++ 4.7"
+			#elif wxCHECK_GCC_VERSION(4,6)
+				"Gnu C++ 4.6"
+			#else
+				"Gnu C++"
+			#endif
 		#elif	defined(__VISUALC__)	// The value of this macro corresponds to the compiler version: 1020 for 4.2 (the first supported version), 1100 for 5.0, 1200 for 6.0 and so on
 			#if   __VISUALC__ == 1020
 				"Microsoft Visual C++ 4.2"
