--- content/renderer/render_view_impl.h.orig	2011-11-01 10:42:35.000000000 +0200
+++ content/renderer/render_view_impl.h	2011-11-22 00:49:03.000000000 +0200
@@ -260,12 +260,12 @@
   // Request updated policy regarding firewall NAT traversal being enabled.
   void RequestRemoteAccessClientFirewallTraversal();
 
-#if defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_FREEBSD)
   // Informs the render view that the given plugin has gained or lost focus.
   void PluginFocusChanged(bool focused, int plugin_id);
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Starts plugin IME.
   void StartPluginIme();
 
@@ -670,7 +670,7 @@
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest, OnUpdateWebPreferences);
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest, StaleNavigationsIgnored);
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest, UpdateTargetURLWithInvalidURL);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, MacTestCmdUp);
 #endif
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest, SetHistoryLengthAndPrune);
@@ -1097,7 +1097,7 @@
   bool cached_has_main_frame_horizontal_scrollbar_;
   bool cached_has_main_frame_vertical_scrollbar_;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Track the fake plugin window handles allocated on the browser side for
   // the accelerated compositor and (currently) accelerated plugins so that
   // we can discard them when the view goes away.
