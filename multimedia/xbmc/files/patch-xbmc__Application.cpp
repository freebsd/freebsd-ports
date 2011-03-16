--- ./xbmc/Application.cpp.orig	2011-03-05 04:33:37.000000000 +0100
+++ ./xbmc/Application.cpp	2011-03-11 08:27:38.000000000 +0100
@@ -495,6 +495,8 @@
   CLog::Log(LOGNOTICE, "-----------------------------------------------------------------------");
 #if defined(__APPLE__)
   CLog::Log(LOGNOTICE, "Starting XBMC, Platform: Mac OS X (%s). Built on %s (Git:%s)", g_sysinfo.GetUnameVersion().c_str(), __DATE__, GIT_REV);
+#elif defined(__FreeBSD__)
+  CLog::Log(LOGNOTICE, "Starting XBMC, Platform: FreeBSD (%s). Built on %s (Git:%s)", g_sysinfo.GetUnameVersion().c_str(), __DATE__, GIT_REV);
 #elif defined(_LINUX)
   CLog::Log(LOGNOTICE, "Starting XBMC, Platform: Linux (%s, %s). Built on %s (Git:%s)", g_sysinfo.GetLinuxDistro().c_str(), g_sysinfo.GetUnameVersion().c_str(), __DATE__, GIT_REV);
 #elif defined(_WIN32)
@@ -785,6 +787,11 @@
       }
     }
   }
+  char resolved_path[PATH_MAX];
+  if (realpath(xbmcPath.c_str(), resolved_path))
+    xbmcPath = resolved_path;
+  if (realpath(xbmcBinPath.c_str(), resolved_path))
+    xbmcBinPath = resolved_path;
 
   /* Set some environment variables */
   setenv("XBMC_BIN_HOME", xbmcBinPath.c_str(), 0);
