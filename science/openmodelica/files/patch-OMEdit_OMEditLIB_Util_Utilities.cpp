--- OMEdit/OMEditLIB/Util/Utilities.cpp.orig	2022-12-11 19:01:44 UTC
+++ OMEdit/OMEditLIB/Util/Utilities.cpp
@@ -1012,7 +1012,7 @@ QIcon Utilities::FileIconProvider::FileIconProviderImp
   // Get icon from OS.
   QIcon icon;
   // File icons are unknown on linux systems.
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_UNIX)
   icon = isDir ? QFileIconProvider::icon(fileInfo) : mUnknownFileIcon;
 #else
   icon = QFileIconProvider::icon(fileInfo);
