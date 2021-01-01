--- chrome/browser/first_run/first_run_dialog.h.orig	2019-07-29 18:50:26 UTC
+++ chrome/browser/first_run/first_run_dialog.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 
 // Hide this function on platforms where the dialog does not exist.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 class Profile;
 
