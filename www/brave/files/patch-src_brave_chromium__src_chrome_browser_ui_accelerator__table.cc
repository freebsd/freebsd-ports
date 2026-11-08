--- src/brave/chromium_src/chrome/browser/ui/accelerator_table.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/ui/accelerator_table.cc
@@ -47,7 +47,7 @@
   // Remove the upstream accelerator for new split tab on Windows and Linux, as
   // it conflicts with our existing Tor shortcut (see `kBraveAcceleratorMap`
   // above)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   std::erase_if(accelerator_list, [](const AcceleratorMapping& m) {
     return m.keycode == ui::VKEY_N &&
            m.modifiers == (ui::EF_SHIFT_DOWN | ui::EF_ALT_DOWN) &&
