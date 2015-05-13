--- osquery/extensions/extensions.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/extensions/extensions.cpp
@@ -76,7 +76,7 @@ EXTENSION_FLAG_ALIAS(socket, extensions_
 EXTENSION_FLAG_ALIAS(timeout, extensions_timeout);
 EXTENSION_FLAG_ALIAS(interval, extensions_interval);
 
-void ExtensionWatcher::enter() {
+void ExtensionWatcher::start() {
   // Watch the manager, if the socket is removed then the extension will die.
   while (true) {
     watch();
