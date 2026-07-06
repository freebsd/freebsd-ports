--- ui/base/ime/text_input_client.h.orig	2026-07-01 06:24:19 UTC
+++ ui/base/ime/text_input_client.h
@@ -342,7 +342,7 @@ class COMPONENT_EXPORT(UI_BASE_IME) TextInputClient {
   virtual bool SupportsAutoFill() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Start composition over a given UTF-16 code range from existing text. This
   // should only be used for composition scenario when IME wants to start
   // composition on existing text. Returns whether the operation was successful.
