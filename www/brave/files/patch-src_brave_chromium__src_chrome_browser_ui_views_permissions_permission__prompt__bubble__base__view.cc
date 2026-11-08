--- src/brave/chromium_src/chrome/browser/ui/views/permissions/permission_prompt_bubble_base_view.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/ui/views/permissions/permission_prompt_bubble_base_view.cc
@@ -145,10 +145,15 @@
                                                 urls));
 }
 #else
+// Keep this in step with the ENABLE_WIDEVINE definition above and with what
+// the call site hands over: PermissionPrompt::Delegate::Requests() returns a
+// vector of unique_ptr, see components/permissions/permission_prompt.h.  The
+// raw_ptr spelling this stub used to carry stopped matching upstream, and
+// nothing caught it because Brave never builds with Widevine off.
 void AddAdditionalWidevineViewControlsIfNeeded(
     views::BubbleDialogDelegateView* dialog_delegate_view,
-    const std::vector<raw_ptr<permissions::PermissionRequest,
-                              VectorExperimental>>& requests) {}
+    const std::vector<std::unique_ptr<permissions::PermissionRequest>>&
+        requests) {}
 #endif
 
 // Custom combobox, shows permission lifetime options and applies selected value
