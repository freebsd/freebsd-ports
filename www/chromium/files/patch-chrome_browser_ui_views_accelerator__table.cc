--- chrome/browser/ui/views/accelerator_table.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/views/accelerator_table.cc
@@ -62,7 +62,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_NUMPAD9, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_LAST_TAB},
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     {ui::VKEY_9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NUMPAD9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT},
@@ -94,7 +94,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_NUMPAD8, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_7},
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     {ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_2, ui::EF_ALT_DOWN, IDC_SELECT_TAB_1},
@@ -139,7 +139,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
      IDC_SHOW_AVATAR_MENU},
 
 // Platform-specific key maps.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK},
     {ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD},
     {ui::VKEY_BROWSER_HOME, ui::EF_NONE, IDC_HOME},
