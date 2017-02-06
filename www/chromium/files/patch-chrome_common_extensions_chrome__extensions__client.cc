--- chrome/common/extensions/chrome_extensions_client.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/common/extensions/chrome_extensions_client.cc
@@ -105,7 +105,10 @@ ChromeChannelForHistogram GetChromeChann
 static base::LazyInstance<ChromeExtensionsClient> g_client =
     LAZY_INSTANCE_INITIALIZER;
 
-ChromeExtensionsClient::ChromeExtensionsClient() {}
+ChromeExtensionsClient::ChromeExtensionsClient()
+    : chrome_api_permissions_(ChromeAPIPermissions()),
+      extensions_api_permissions_(ExtensionsAPIPermissions()) {
+}
 
 ChromeExtensionsClient::~ChromeExtensionsClient() {
 }
