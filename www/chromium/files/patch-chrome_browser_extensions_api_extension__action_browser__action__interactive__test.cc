--- chrome/browser/extensions/api/extension_action/browser_action_interactive_test.cc.orig	2020-07-13 09:17:42 UTC
+++ chrome/browser/extensions/api/extension_action/browser_action_interactive_test.cc
@@ -280,7 +280,7 @@ IN_PROC_BROWSER_TEST_F(BrowserActionInteractiveTest, T
   frame_observer.Wait();
   // Non-Aura Linux uses a singleton for the popup, so it looks like all windows
   // have popups if there is any popup open.
-#if !(defined(OS_LINUX) && !defined(USE_AURA))
+#if !((defined(OS_LINUX) || defined(OS_BSD)) && !defined(USE_AURA))
   // Starting window does not have a popup.
   EXPECT_FALSE(ExtensionActionTestHelper::Create(browser())->HasPopup());
 #endif
