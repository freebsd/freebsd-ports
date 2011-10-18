--- content/renderer/render_view.h.orig	2011-09-10 18:40:54.000000000 +0300
+++ content/renderer/render_view.h	2011-09-10 19:13:46.000000000 +0300
@@ -312,7 +312,7 @@
   // Request updated policy regarding firewall NAT traversal being enabled.
   void RequestRemoteAccessClientFirewallTraversal();
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Informs the render view that the given plugin has gained or lost focus.
   void PluginFocusChanged(bool focused, int plugin_id);
 
@@ -654,7 +654,7 @@
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, OnSetTextDirection);
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, StaleNavigationsIgnored);
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, UpdateTargetURLWithInvalidURL);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, MacTestCmdUp);
 #endif
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, SetHistoryLengthAndPrune);
@@ -1079,7 +1079,7 @@
   // states for the sizes).
   base::OneShotTimer<RenderView> check_preferred_size_timer_;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Track the fake plugin window handles allocated on the browser side for
   // the accelerated compositor and (currently) accelerated plugins so that
   // we can discard them when the view goes away.
