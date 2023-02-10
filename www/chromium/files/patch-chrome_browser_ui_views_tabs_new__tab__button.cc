--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2023-02-08 09:03:45 UTC
+++ chrome/browser/ui/views/tabs/new_tab_button.cc
@@ -61,7 +61,7 @@ NewTabButton::NewTabButton(TabStrip* tab_strip, Presse
   SetAnimateOnStateChange(true);
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   SetTriggerableEventFlags(GetTriggerableEventFlags() |
                            ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
