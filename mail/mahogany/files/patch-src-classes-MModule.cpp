--- src/classes/MModule.cpp.orig	Tue Jul 22 14:07:38 2003
+++ src/classes/MModule.cpp	Sun Oct  5 03:02:24 2003
@@ -870,10 +870,7 @@
    // platforms (doesn't make much sense under Windows)
 
    wxString path1;
-   path1 << mApplication->GetGlobalDir()
-#ifdef OS_UNIX
-         << DIR_SEPARATOR << M_CANONICAL_HOST
-#endif // Unix
+   path1 << M_PREFIX << DIR_SEPARATOR << "libexec" << DIR_SEPARATOR << "Mahogany"
          << DIR_SEPARATOR << _T("modules") << DIR_SEPARATOR;
 
    dirs.Add(path1);
