--- ui/compositor/host/host_context_factory_private.cc.orig	2020-03-16 18:40:43 UTC
+++ ui/compositor/host/host_context_factory_private.cc
@@ -29,7 +29,7 @@ namespace {
 
 static const char* kBrowser = "Browser";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 class HostDisplayClient : public viz::HostDisplayClient {
  public:
   explicit HostDisplayClient(ui::Compositor* compositor)
