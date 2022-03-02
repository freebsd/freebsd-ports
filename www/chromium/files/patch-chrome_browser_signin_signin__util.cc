--- chrome/browser/signin/signin_util.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -41,7 +41,7 @@
 #include "ui/base/l10n/l10n_util.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
