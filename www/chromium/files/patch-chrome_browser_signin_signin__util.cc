--- chrome/browser/signin/signin_util.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -40,7 +40,7 @@
 #include "ui/base/l10n/l10n_util.h"
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
