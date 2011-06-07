--- content/renderer/webplugin_delegate_proxy.h.orig	2011-03-23 00:46:31.521939657 +0200
+++ content/renderer/webplugin_delegate_proxy.h	2011-03-23 00:47:12.163682393 +0200
@@ -21,7 +21,7 @@
 #include "webkit/plugins/npapi/webplugininfo.h"
 #include "webkit/plugins/npapi/webplugin_delegate.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include "base/hash_tables.h"
 #include "base/linked_ptr.h"
 #endif
@@ -216,7 +216,7 @@
   // point the window has already been destroyed).
   void WillDestroyWindow();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Synthesize a fake window handle for the plug-in to identify the instance
   // to the browser, allowing mapping to a surface for hardware acceleration
   // of plug-in content. The browser generates the handle which is then set on
