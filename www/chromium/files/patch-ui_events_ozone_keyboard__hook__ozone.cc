--- ui/events/ozone/keyboard_hook_ozone.cc.orig	2021-07-19 18:45:44 UTC
+++ ui/events/ozone/keyboard_hook_ozone.cc
@@ -34,7 +34,7 @@ bool KeyboardHookOzone::IsKeyLocked(DomCode dom_code) 
   return platform_keyboard_hook_->IsKeyLocked(dom_code);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // static
 std::unique_ptr<KeyboardHook> KeyboardHook::CreateModifierKeyboardHook(
     absl::optional<base::flat_set<DomCode>> dom_codes,
