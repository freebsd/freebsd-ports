--- xbmc/filesystem/CacheStrategy.cpp.orig
+++ xbmc/filesystem/CacheStrategy.cpp
@@ -93,7 +93,8 @@
 
   if(m_hCacheFileWrite == INVALID_HANDLE_VALUE)
   {
-    CLog::Log(LOGERROR, "%s - failed to create file %s with error code %d", __FUNCTION__, fileName.c_str(), GetLastError());
+    CLog::Log(LOGERROR, "%s - failed to create file %s with error code %d",
+      __FUNCTION__, fileName.c_str(), (int)GetLastError());
     Close();
     return CACHE_RC_ERROR;
   }
@@ -107,7 +108,8 @@
 
   if(m_hCacheFileRead == INVALID_HANDLE_VALUE)
   {
-    CLog::Log(LOGERROR, "%s - failed to open file %s with error code %d", __FUNCTION__, fileName.c_str(), GetLastError());
+    CLog::Log(LOGERROR, "%s - failed to open file %s with error code %d",
+      __FUNCTION__, fileName.c_str(), (int)GetLastError());
     Close();
     return CACHE_RC_ERROR;
   }
@@ -140,8 +142,8 @@
   DWORD iWritten=0;
   if (!WriteFile(m_hCacheFileWrite, pBuffer, iSize, &iWritten, NULL))
   {
-    CLog::Log(LOGERROR, "%s - failed to write to file. err: %u",
-                          __FUNCTION__, GetLastError());
+    CLog::Log(LOGERROR, "%s - failed to write to file. err: %d",
+                          __FUNCTION__, (int)GetLastError());
     return CACHE_RC_ERROR;
   }
 
