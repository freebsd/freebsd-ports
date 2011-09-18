--- content/renderer/webplugin_delegate_proxy.h.orig	2011-09-11 19:07:19.000000000 +0300
+++ content/renderer/webplugin_delegate_proxy.h	2011-09-11 19:07:36.000000000 +0300
@@ -21,7 +21,7 @@
 #include "webkit/plugins/npapi/webplugininfo.h"
 #include "webkit/plugins/npapi/webplugin_delegate.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include "base/hash_tables.h"
 #include "base/memory/linked_ptr.h"
 #endif
@@ -243,7 +243,7 @@
   // point the window has already been destroyed).
   void WillDestroyWindow();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Synthesize a fake window handle for the plug-in to identify the instance
   // to the browser, allowing mapping to a surface for hardware acceleration
   // of plug-in content. The browser generates the handle which is then set on
