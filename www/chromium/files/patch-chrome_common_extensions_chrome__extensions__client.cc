--- chrome/common/extensions/chrome_extensions_client.cc.orig	2016-12-16 03:27:01.063936000 +0000
+++ chrome/common/extensions/chrome_extensions_client.cc	2016-12-16 03:29:25.710522000 +0000
@@ -103,7 +103,10 @@
 static base::LazyInstance<ChromeExtensionsClient> g_client =
     LAZY_INSTANCE_INITIALIZER;
 
-ChromeExtensionsClient::ChromeExtensionsClient() {}
+ChromeExtensionsClient::ChromeExtensionsClient()
+    : chrome_api_permissions_(ChromeAPIPermissions()),
+      extensions_api_permissions_(ExtensionsAPIPermissions()) {
+}
 
 ChromeExtensionsClient::~ChromeExtensionsClient() {
 }
