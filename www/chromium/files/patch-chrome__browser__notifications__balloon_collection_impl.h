--- ./chrome/browser/notifications/balloon_collection_impl.h.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./chrome/browser/notifications/balloon_collection_impl.h	2010-12-20 20:15:08.000000000 +0100
@@ -56,7 +56,7 @@
   virtual void WillProcessMessage(const MSG& event) {}
   virtual void DidProcessMessage(const MSG& event);
 #endif
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   virtual void WillProcessEvent(GdkEvent* event) {}
   virtual void DidProcessEvent(GdkEvent* event);
 #endif
