--- content/renderer/render_view_impl.h.orig	2012-09-25 16:01:33.000000000 +0300
+++ content/renderer/render_view_impl.h	2012-09-29 17:42:16.000000000 +0300
@@ -344,12 +344,12 @@
   void SimulateImeConfirmComposition(const string16& text,
                                      const ui::Range& replacement_range);
 
-#if defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_FREEBSD)
   // Informs the render view that the given plugin has gained or lost focus.
   void PluginFocusChanged(bool focused, int plugin_id);
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Starts plugin IME.
   void StartPluginIme();
 
@@ -799,7 +799,7 @@
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest,
                            GetCompositionCharacterBoundsTest);
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest, OnNavigationHttpPost);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   FRIEND_TEST_ALL_PREFIXES(RenderViewTest, MacTestCmdUp);
 #endif
   FRIEND_TEST_ALL_PREFIXES(RenderViewImplTest, SetHistoryLengthAndPrune);
@@ -1271,7 +1271,7 @@
   bool cached_has_main_frame_horizontal_scrollbar_;
   bool cached_has_main_frame_vertical_scrollbar_;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Track the fake plugin window handles allocated on the browser side for
   // the accelerated compositor and (currently) accelerated plugins so that
   // we can discard them when the view goes away.
