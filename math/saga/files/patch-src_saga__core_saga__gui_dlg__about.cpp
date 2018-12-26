--- src/saga_core/saga_gui/dlg_about.cpp.orig	2018-11-22 07:53:06 UTC
+++ src/saga_core/saga_gui/dlg_about.cpp
@@ -188,6 +188,7 @@ wxString CDLG_About::_Get_Version(void)
 	s	+= "http://www.saga-gis.org\n";
 	s	+= "\n";
 	s	+= "Version: " + wxString(SAGA_VERSION) + "\n";
+	s	+= "https://sourceforge.net/p/saga-gis/code/ci/release-PORTVERSION/tree/\n";
 
 #ifdef _SAGA_MSW
 	#ifdef _WIN64
@@ -263,7 +264,47 @@ wxString CDLG_About::_Get_Version(void)
 		#elif	defined(__GNUWIN32__)
 			"Gnu-Win32 compiler"
 		#elif	defined(__GNUG__)
-			"Gnu C++"
+			#if   wxCHECK_GCC_VERSION(6,4)
+				"Gnu C++ 6.4"
+			#elif wxCHECK_GCC_VERSION(6,3)
+				"Gnu C++ 6.3"
+			#elif wxCHECK_GCC_VERSION(6,2)
+				"Gnu C++ 6.2"
+			#elif wxCHECK_GCC_VERSION(6,1)
+				"Gnu C++ 6.1"
+			#elif wxCHECK_GCC_VERSION(6,0)
+				"Gnu C++ 6.0"
+			#elif wxCHECK_GCC_VERSION(5,9)
+				"Gnu C++ 5.9"
+			#elif wxCHECK_GCC_VERSION(5,8)
+				"Gnu C++ 5.8"
+			#elif wxCHECK_GCC_VERSION(5,7)
+				"Gnu C++ 5.7"
+			#elif wxCHECK_GCC_VERSION(5,6)
+				"Gnu C++ 5.6"
+			#elif wxCHECK_GCC_VERSION(5,5)
+				"Gnu C++ 5.5"
+			#elif wxCHECK_GCC_VERSION(5,4)
+				"Gnu C++ 5.4"
+			#elif wxCHECK_GCC_VERSION(5,3)
+				"Gnu C++ 5.3"
+			#elif wxCHECK_GCC_VERSION(5,2)
+				"Gnu C++ 5.2"
+			#elif wxCHECK_GCC_VERSION(5,1)
+				"Gnu C++ 5.1"
+			#elif wxCHECK_GCC_VERSION(5,0)
+				"Gnu C++ 5.0"
+			#elif wxCHECK_GCC_VERSION(4,9)
+				"Gnu C++ 4.9"
+			#elif wxCHECK_GCC_VERSION(4,8)
+				"Gnu C++ 4.8"
+			#elif wxCHECK_GCC_VERSION(4,7)
+				"Gnu C++ 4.7"
+			#elif wxCHECK_GCC_VERSION(4,6)
+				"Gnu C++ 4.6"
+			#else
+				"Gnu C++"
+			#endif
 		#elif	defined(__VISUALC__)	// The value of this macro corresponds to the compiler version: 1020 for 4.2 (the first supported version), 1100 for 5.0, 1200 for 6.0 and so on
 			#if   __VISUALC__ == 1020
 				"Microsoft Visual C++ 4.2"
