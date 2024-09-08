--- chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2024-08-26 14:40:28 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -82,7 +82,7 @@
 #include "ui/strings/grit/ui_strings.h"
 #include "ui/views/accessibility/view_accessibility.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
