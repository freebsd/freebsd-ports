--- xbmc/Util.cpp.orig	2010-12-17 07:17:41.000000000 +0100
+++ xbmc/Util.cpp	2010-12-27 20:40:24.000000000 +0100
@@ -27,6 +27,11 @@
 #include <mach-o/dyld.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #ifdef _LINUX
 #include <sys/types.h>
 #include <dirent.h>
@@ -1434,7 +1439,7 @@
 
 void CUtil::CacheSubtitles(const CStdString& strMovie, CStdString& strExtensionCached, XFILE::IFileCallback *pCallback )
 {
-  unsigned int startTimer = CTimeUtils::GetTimeMS();
+  DWORD startTimer = CTimeUtils::GetTimeMS();
   CLog::Log(LOGDEBUG,"%s: START", __FUNCTION__);
 
   // new array for commons sub dirs
@@ -1546,7 +1551,7 @@
     strLookInPaths.push_back(strPath);
   }
 
-  unsigned int nextTimer = CTimeUtils::GetTimeMS();
+  DWORD nextTimer = CTimeUtils::GetTimeMS();
   CLog::Log(LOGDEBUG,"%s: Done (time: %i ms)", __FUNCTION__, (int)(nextTimer - startTimer));
 
   CStdString strLExt;
@@ -3440,6 +3445,22 @@
   if (result == 0)
     realpath(given_path, real_given_path);
   strExecutablePath = real_given_path;
+#elif defined(__FreeBSD__)
+  char buf[PATH_MAX];
+  size_t buflen;
+  int mib[4];
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PATHNAME;
+  mib[3] = getpid();
+
+  buflen = sizeof(buf) - 1;
+
+  if(sysctl(mib, 4, buf, &buflen, NULL, 0) < 0)
+    strExecutablePath = "";
+  else
+    strExecutablePath = buf;
 #else
   /* Get our PID and build the name of the link in /proc */
   pid_t pid = getpid();
