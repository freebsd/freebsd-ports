--- remoting/host/heartbeat_sender.cc.orig	2021-01-19 11:48:10 UTC
+++ remoting/host/heartbeat_sender.cc
@@ -109,7 +109,7 @@ const net::BackoffEntry::Policy kBackoffPolicy = {
 };
 
 std::string GetHostname() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return net::GetHostName();
 #elif defined(OS_WIN)
   wchar_t buffer[MAX_PATH] = {0};
