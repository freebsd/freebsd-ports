--- remoting/host/remote_open_url/remote_open_url_client.cc.orig	2021-12-16 15:17:34 UTC
+++ remoting/host/remote_open_url/remote_open_url_client.cc
@@ -14,7 +14,7 @@
 #include "remoting/base/logging.h"
 #include "remoting/host/remote_open_url/remote_open_url_constants.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "remoting/host/remote_open_url/remote_open_url_client_delegate_linux.h"
 #elif defined(OS_WIN)
 #include "remoting/host/remote_open_url/remote_open_url_client_delegate_win.h"
@@ -27,7 +27,7 @@ namespace {
 constexpr base::TimeDelta kRequestTimeout = base::Seconds(5);
 
 std::unique_ptr<RemoteOpenUrlClient::Delegate> CreateDelegate() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<RemoteOpenUrlClientDelegateLinux>();
 #elif defined(OS_WIN)
   return std::make_unique<RemoteOpenUrlClientDelegateWin>();
