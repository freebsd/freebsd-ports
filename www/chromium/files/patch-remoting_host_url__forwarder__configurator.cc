--- remoting/host/url_forwarder_configurator.cc.orig	2021-09-24 18:54:47 UTC
+++ remoting/host/url_forwarder_configurator.cc
@@ -13,7 +13,7 @@ UrlForwarderConfigurator::UrlForwarderConfigurator() =
 
 UrlForwarderConfigurator::~UrlForwarderConfigurator() = default;
 
-#if !defined(OS_LINUX) && !defined(OS_WIN)
+#if !defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_BSD)
 
 // static
 std::unique_ptr<UrlForwarderConfigurator> UrlForwarderConfigurator::Create() {
@@ -22,6 +22,6 @@ std::unique_ptr<UrlForwarderConfigurator> UrlForwarder
   return nullptr;
 }
 
-#endif  // !defined(OS_LINUX) && !defined(OS_WIN)
+#endif  // !defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_BSD)
 
 }  // namespace remoting
