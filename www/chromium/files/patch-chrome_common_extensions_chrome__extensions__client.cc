--- chrome/common/extensions/chrome_extensions_client.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/common/extensions/chrome_extensions_client.cc
@@ -97,7 +97,10 @@ ChromeChannelForHistogram GetChromeChann
 static base::LazyInstance<ChromeExtensionsClient> g_client =
     LAZY_INSTANCE_INITIALIZER;
 
-ChromeExtensionsClient::ChromeExtensionsClient() {}
+ChromeExtensionsClient::ChromeExtensionsClient()
+    : chrome_api_permissions_(ChromeAPIPermissions()),
+      extensions_api_permissions_(ExtensionsAPIPermissions()) {
+}
 
 ChromeExtensionsClient::~ChromeExtensionsClient() {
 }
