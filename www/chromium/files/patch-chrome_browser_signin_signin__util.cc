--- chrome/browser/signin/signin_util.cc.orig	2021-09-24 04:25:59 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -37,7 +37,7 @@
 #include "google_apis/gaia/gaia_auth_util.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_list.h"
