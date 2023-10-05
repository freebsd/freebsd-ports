--- OMEdit/OMEditLIB/Util/Utilities.cpp.orig	2023-04-14 14:33:28 UTC
+++ OMEdit/OMEditLIB/Util/Utilities.cpp
@@ -1019,7 +1019,7 @@ QIcon Utilities::FileIconProvider::FileIconProviderImp
   // Get icon from OS.
   QIcon icon;
   // File icons are unknown on linux systems.
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_UNIX)
   icon = isDir ? QFileIconProvider::icon(fileInfo) : mUnknownFileIcon;
 #else
   icon = QFileIconProvider::icon(fileInfo);
