--- ui/views/controls/prefix_selector.cc.orig	2021-12-16 15:23:23 UTC
+++ ui/views/controls/prefix_selector.cc
@@ -171,7 +171,7 @@ bool PrefixSelector::ShouldDoLearning() {
   return false;
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool PrefixSelector::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
