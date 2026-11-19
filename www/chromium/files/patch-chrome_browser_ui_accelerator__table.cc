--- chrome/browser/ui/accelerator_table.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/accelerator_table.cc
@@ -232,7 +232,7 @@ constexpr AcceleratorMapping kChromeOSAcceleratorMap[]
 };
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr AcceleratorMapping kLinuxAndChromeOSAcceleratorMap[] = {
     {ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK},
     {ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD},
@@ -245,7 +245,7 @@ constexpr AcceleratorMapping kLinuxAndChromeOSAccelera
 };
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr AcceleratorMapping kLinuxAndWinAcceleratorMap[] = {
     {ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT},
     {ui::VKEY_PRIOR, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN,
@@ -254,7 +254,7 @@ constexpr AcceleratorMapping kLinuxAndWinAcceleratorMa
 };
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 constexpr AcceleratorMapping kAltTabSelectAcceleratorMap[] = {
     {ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
@@ -277,7 +277,7 @@ constexpr AcceleratorMapping kAltTabSelectAcceleratorM
 };
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr AcceleratorMapping kLinuxAcceleratorMap[] = {
     {ui::VKEY_BROWSER_FAVORITES, ui::EF_NONE, IDC_SHOW_BOOKMARK_BAR},
 };
@@ -393,16 +393,16 @@ std::vector<AcceleratorMapping> GetAcceleratorList() {
 #if BUILDFLAG(IS_CHROMEOS)
         kChromeOSAcceleratorMap,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         kLinuxAndChromeOSAcceleratorMap,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         kLinuxAndWinAcceleratorMap,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         kAltTabSelectAcceleratorMap,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         kLinuxAcceleratorMap,
 #endif
 #if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
