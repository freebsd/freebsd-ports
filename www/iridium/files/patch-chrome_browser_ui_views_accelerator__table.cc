--- chrome/browser/ui/views/accelerator_table.cc.orig	2018-05-09 21:05:40.000000000 +0200
+++ chrome/browser/ui/views/accelerator_table.cc	2018-08-16 09:05:20.123832000 +0200
@@ -48,7 +48,7 @@
   { ui::VKEY_S, kPlatformModifier, IDC_SAVE_PAGE },
   { ui::VKEY_9, kPlatformModifier, IDC_SELECT_LAST_TAB },
   { ui::VKEY_NUMPAD9, kPlatformModifier, IDC_SELECT_LAST_TAB },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   { ui::VKEY_9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB },
   { ui::VKEY_NUMPAD9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB },
   { ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT },
@@ -78,7 +78,7 @@
   { ui::VKEY_NUMPAD7, kPlatformModifier, IDC_SELECT_TAB_6 },
   { ui::VKEY_8, kPlatformModifier, IDC_SELECT_TAB_7 },
   { ui::VKEY_NUMPAD8, kPlatformModifier, IDC_SELECT_TAB_7 },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   { ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0 },
   { ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0 },
   { ui::VKEY_2, ui::EF_ALT_DOWN, IDC_SELECT_TAB_1 },
@@ -123,7 +123,7 @@
 #endif  // !OS_MACOSX
 
   // Platform-specific key maps.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   { ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK },
   { ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD },
   { ui::VKEY_BROWSER_HOME, ui::EF_NONE, IDC_HOME },
