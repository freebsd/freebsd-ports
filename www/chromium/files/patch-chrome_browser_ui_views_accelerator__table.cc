--- chrome/browser/ui/views/accelerator_table.cc.orig	2017-02-02 02:02:50 UTC
+++ chrome/browser/ui/views/accelerator_table.cc
@@ -72,7 +72,7 @@ const AcceleratorMapping kAcceleratorMap
   { ui::VKEY_S, ui::EF_CONTROL_DOWN, IDC_SAVE_PAGE },
   { ui::VKEY_9, kPlatformModifier, IDC_SELECT_LAST_TAB },
   { ui::VKEY_NUMPAD9, kPlatformModifier, IDC_SELECT_LAST_TAB },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   { ui::VKEY_9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB },
   { ui::VKEY_NUMPAD9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB },
   { ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT },
@@ -100,7 +100,7 @@ const AcceleratorMapping kAcceleratorMap
   { ui::VKEY_NUMPAD7, kPlatformModifier, IDC_SELECT_TAB_6 },
   { ui::VKEY_8, kPlatformModifier, IDC_SELECT_TAB_7 },
   { ui::VKEY_NUMPAD8, kPlatformModifier, IDC_SELECT_TAB_7 },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   { ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0 },
   { ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0 },
   { ui::VKEY_2, ui::EF_ALT_DOWN, IDC_SELECT_TAB_1 },
@@ -149,7 +149,7 @@ const AcceleratorMapping kAcceleratorMap
   { ui::VKEY_F11, ui::EF_NONE, IDC_FULLSCREEN },
 
   // Platform-specific key maps.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   { ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK },
   { ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD },
   { ui::VKEY_BROWSER_HOME, ui::EF_NONE, IDC_HOME },
