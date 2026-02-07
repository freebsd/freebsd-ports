--- core/DesktopEditor/pluginsmanager/main.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/DesktopEditor/pluginsmanager/main.cpp
@@ -52,7 +52,7 @@
 #undef GetTempPath
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <stdio.h>
 #endif
@@ -270,7 +270,7 @@ class CPluginsManager (public)
 
 		m_sSettingsDir = NSSystemUtils::GetAppDataDir() + L"/pluginsmanager";
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 		// GetAppDataDir creates folder with ONLYOFFICE on Linux
 		// as result - two folders in lower/upper case, working with the correct folder
 		NSStringUtils::string_replace(m_sSettingsDir, L"ONLYOFFICE", L"onlyoffice");
