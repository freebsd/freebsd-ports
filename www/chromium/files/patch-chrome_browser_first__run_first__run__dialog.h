--- chrome/browser/first_run/first_run_dialog.h.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/first_run/first_run_dialog.h
@@ -12,7 +12,7 @@
 // Hide this function on platforms where the dialog does not exist.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 
 class Profile;
 
