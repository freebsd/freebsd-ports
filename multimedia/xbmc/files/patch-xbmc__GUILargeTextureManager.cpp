--- ./xbmc/GUILargeTextureManager.cpp.orig	2010-10-08 04:41:58.000000000 +0200
+++ ./xbmc/GUILargeTextureManager.cpp	2010-12-01 12:17:34.238812978 +0100
@@ -68,7 +68,8 @@
       m_texture = NULL;
     }
     else if (CTimeUtils::GetTimeMS() - start > 100)
-      CLog::Log(LOGDEBUG, "%s - took %d ms to load %s", __FUNCTION__, CTimeUtils::GetTimeMS() - start, loadPath.c_str());
+      CLog::Log(LOGDEBUG, "%s - took %d ms to load %s", __FUNCTION__,
+        (int)(CTimeUtils::GetTimeMS() - start), loadPath.c_str());
   }
 
   return true;
