--- ui/base/ime/text_input_client.h.orig	2021-12-16 15:21:05 UTC
+++ ui/base/ime/text_input_client.h
@@ -237,7 +237,7 @@ class COMPONENT_EXPORT(UI_BASE_IME) TextInputClient {
   // fields that are considered 'private' (e.g. in incognito tabs).
   virtual bool ShouldDoLearning() = 0;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Start composition over a given UTF-16 code range from existing text. This
   // should only be used for composition scenario when IME wants to start
   // composition on existing text. Returns whether the operation was successful.
