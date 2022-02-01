--- remoting/host/remote_open_url/remote_open_url_util.cc.orig	2021-12-16 15:17:52 UTC
+++ remoting/host/remote_open_url/remote_open_url_util.cc
@@ -30,7 +30,7 @@ const wchar_t kRegisteredApplicationsKeyName[] =
 #endif  // defined (OS_WIN)
 
 bool IsRemoteOpenUrlSupported() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN)
   // The modern default apps settings dialog is only available to Windows 8+.
