--- chrome/browser/ui/browser_view_prefs.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -10,7 +10,7 @@
 #include "components/prefs/pref_registry_simple.h"
 #include "components/prefs/pref_service.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/x/x11_util.h"  // nogncheck
 #endif
 
