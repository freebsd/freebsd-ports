--- ./xbmc/Application.cpp.orig	2010-10-31 14:58:11.000000000 +0100
+++ ./xbmc/Application.cpp	2010-12-01 12:17:34.231763652 +0100
@@ -494,6 +494,8 @@
   CLog::Log(LOGNOTICE, "-----------------------------------------------------------------------");
 #if defined(__APPLE__)
   CLog::Log(LOGNOTICE, "Starting XBMC, Platform: Mac OS X (%s). Built on %s (SVN:%s)", g_sysinfo.GetUnameVersion().c_str(), __DATE__, SVN_REV);
+#elif defined(__FreeBSD__)
+  CLog::Log(LOGNOTICE, "Starting XBMC, Platform: FreeBSD (%s). Built on %s (SVN:%s)", g_sysinfo.GetUnameVersion().c_str(), __DATE__, SVN_REV);
 #elif defined(_LINUX)
   CLog::Log(LOGNOTICE, "Starting XBMC, Platform: Linux (%s, %s). Built on %s (SVN:%s)", g_sysinfo.GetLinuxDistro().c_str(), g_sysinfo.GetUnameVersion().c_str(), __DATE__, SVN_REV);
 #elif defined(_WIN32)
@@ -777,6 +779,11 @@
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
