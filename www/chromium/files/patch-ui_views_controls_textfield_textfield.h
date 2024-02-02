--- ui/views/controls/textfield/textfield.h.orig	2024-01-30 07:53:34 UTC
+++ ui/views/controls/textfield/textfield.h
@@ -46,7 +46,7 @@
 #include "ui/views/view.h"
 #include "ui/views/word_lookup_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <vector>
 #endif
 
@@ -454,7 +454,7 @@ class VIEWS_EXPORT Textfield : public View,
   // Set whether the text should be used to improve typing suggestions.
   void SetShouldDoLearning(bool value) { should_do_learning_ = value; }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
