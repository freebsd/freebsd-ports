--- components/network_session_configurator/browser/network_session_configurator_unittest.cc.orig	2024-09-30 07:45:04 UTC
+++ components/network_session_configurator/browser/network_session_configurator_unittest.cc
@@ -828,7 +828,7 @@ TEST_F(NetworkSessionConfiguratorTest, HostRules) {
 
 TEST_F(NetworkSessionConfiguratorTest, DefaultCacheBackend) {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE,
             ChooseCacheType());
 #else
