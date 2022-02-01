--- remoting/host/heartbeat_sender.cc.orig	2021-12-14 11:45:09 UTC
+++ remoting/host/heartbeat_sender.cc
@@ -111,7 +111,7 @@ const net::BackoffEntry::Policy kBackoffPolicy = {
 std::string GetHostname() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag
 // switch of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return net::GetHostName();
 #elif defined(OS_WIN)
   wchar_t buffer[MAX_PATH] = {0};
