--- chrome/common/extensions/chrome_extensions_client.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/common/extensions/chrome_extensions_client.cc
@@ -97,7 +97,10 @@ ChromeChannelForHistogram GetChromeChannelForHistogram
 static base::LazyInstance<ChromeExtensionsClient>::DestructorAtExit g_client =
     LAZY_INSTANCE_INITIALIZER;
 
-ChromeExtensionsClient::ChromeExtensionsClient() {}
+ChromeExtensionsClient::ChromeExtensionsClient()
+    : chrome_api_permissions_(ChromeAPIPermissions()),
+      extensions_api_permissions_(ExtensionsAPIPermissions()) {
+}
 
 ChromeExtensionsClient::~ChromeExtensionsClient() {
 }
