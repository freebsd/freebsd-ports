--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2024-08-19 06:28:38 UTC
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -68,7 +68,7 @@ CString currentExecutablePath()
         return { };
     return CString({ readLinkBuffer, static_cast<size_t>(result) });
 }
-#elif OS(HURD)
+#elif OS(HURD) || OS(FREEBSD) || OS(OPENBSD)
 CString currentExecutablePath()
 {
     return { };
