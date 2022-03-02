--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/views/tabs/new_tab_button.cc
@@ -59,7 +59,7 @@ NewTabButton::NewTabButton(TabStrip* tab_strip, Presse
   SetAnimateOnStateChange(true);
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   SetTriggerableEventFlags(GetTriggerableEventFlags() |
                            ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
