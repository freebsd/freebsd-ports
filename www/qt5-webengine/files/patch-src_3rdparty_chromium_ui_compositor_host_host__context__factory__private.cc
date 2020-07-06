--- src/3rdparty/chromium/ui/compositor/host/host_context_factory_private.cc.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/ui/compositor/host/host_context_factory_private.cc
@@ -31,7 +31,7 @@ namespace {
 
 static const char* kBrowser = "Browser";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 class HostDisplayClient : public viz::HostDisplayClient {
  public:
   explicit HostDisplayClient(ui::Compositor* compositor)
