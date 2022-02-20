--- remoting/host/remote_open_url/url_forwarder_configurator.cc.orig	2022-02-07 13:39:41 UTC
+++ remoting/host/remote_open_url/url_forwarder_configurator.cc
@@ -12,7 +12,7 @@ UrlForwarderConfigurator::UrlForwarderConfigurator() =
 
 UrlForwarderConfigurator::~UrlForwarderConfigurator() = default;
 
-#if !defined(OS_LINUX) && !defined(OS_WIN)
+#if !defined(OS_LINUX) && !defined(OS_WIN) && !defined(OS_BSD)
 
 // static
 std::unique_ptr<UrlForwarderConfigurator> UrlForwarderConfigurator::Create() {
