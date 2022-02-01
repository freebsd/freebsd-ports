--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/views/tabs/new_tab_button.cc
@@ -59,7 +59,7 @@ NewTabButton::NewTabButton(TabStrip* tab_strip, Presse
   SetAnimateOnStateChange(true);
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   SetTriggerableEventFlags(GetTriggerableEventFlags() |
                            ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
