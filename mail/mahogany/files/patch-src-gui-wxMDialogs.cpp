--- src/gui/wxMDialogs.cpp.orig	Wed Jul 23 00:01:41 2003
+++ src/gui/wxMDialogs.cpp	Sun Oct  5 03:10:29 2003
@@ -1286,19 +1286,9 @@
 {
    String dir, filename;
 
-   // Tips files are in @prefix@/share/Mahogany/doc/Tips/
-   dir = mApplication->GetGlobalDir();
-   if ( !dir )
-   {
-      // like this, it will work in an uninstalled copy of M too
-      dir = _T("..");
-   }
-
-   dir << DIR_SEPARATOR << _T("doc") << DIR_SEPARATOR
-#ifndef OS_WIN
-       << _T("Tips") << DIR_SEPARATOR
-#endif // !Windows
-       ;
+   // Tips files are in @prefix@/share/doc/Mahogany/Tips/
+   dir << M_PREFIX << DIR_SEPARATOR << "share" << DIR_SEPARATOR << "doc";
+   dir << DIR_SEPARATOR << "Mahogany" << DIR_SEPARATOR << "Tips" << DIR_SEPARATOR;
 
    // Tips files are either Tips_LOCALENAME.txt, e.g. Tips_de.txt or
    // simply Tips.txt
