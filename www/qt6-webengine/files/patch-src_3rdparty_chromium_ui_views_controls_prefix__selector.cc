--- src/3rdparty/chromium/ui/views/controls/prefix_selector.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/views/controls/prefix_selector.cc
@@ -192,7 +192,7 @@ bool PrefixSelector::ShouldDoLearning() {
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool PrefixSelector::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
