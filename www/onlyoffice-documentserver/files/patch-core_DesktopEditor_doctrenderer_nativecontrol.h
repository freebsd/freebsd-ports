--- core/DesktopEditor/doctrenderer/nativecontrol.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/nativecontrol.h
@@ -327,7 +327,7 @@ class CNativeControl (public)
 
             if (m_map_access_directories.end() == m_map_access_directories.find(NSFile::GetDirectoryName(strFile)))
             {
-                *pData = NULL;
+                pData = NULL;
                 dwLen = 0;
                 return;
             }
