--- ui/base/ime/text_input_client.h.orig	2022-02-28 16:54:41 UTC
+++ ui/base/ime/text_input_client.h
@@ -237,7 +237,7 @@ class COMPONENT_EXPORT(UI_BASE_IME) TextInputClient {
   // fields that are considered 'private' (e.g. in incognito tabs).
   virtual bool ShouldDoLearning() = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Start composition over a given UTF-16 code range from existing text. This
   // should only be used for composition scenario when IME wants to start
   // composition on existing text. Returns whether the operation was successful.
