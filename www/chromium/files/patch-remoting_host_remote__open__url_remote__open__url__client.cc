--- remoting/host/remote_open_url/remote_open_url_client.cc.orig	2022-02-07 13:39:41 UTC
+++ remoting/host/remote_open_url/remote_open_url_client.cc
@@ -15,7 +15,7 @@
 #include "remoting/host/mojom/chromoting_host_services.mojom.h"
 #include "remoting/host/mojom/remote_url_opener.mojom.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "remoting/host/remote_open_url/remote_open_url_client_delegate_linux.h"
 #elif defined(OS_WIN)
 #include "remoting/host/remote_open_url/remote_open_url_client_delegate_win.h"
@@ -28,7 +28,7 @@ namespace {
 constexpr base::TimeDelta kRequestTimeout = base::Seconds(5);
 
 std::unique_ptr<RemoteOpenUrlClient::Delegate> CreateDelegate() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<RemoteOpenUrlClientDelegateLinux>();
 #elif defined(OS_WIN)
   return std::make_unique<RemoteOpenUrlClientDelegateWin>();
