--- chrome/test/testing_profile.cc.orig	2011-01-26 10:31:06.000000000 +0100
+++ chrome/test/testing_profile.cc	2011-01-30 14:14:21.000000000 +0100
@@ -49,7 +49,7 @@
 #include "testing/gmock/include/gmock/gmock.h"
 #include "webkit/database/database_tracker.h"
 
-#if defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#if defined(TOOLKIT_GTK) && !defined(TOOLKIT_VIEWS)
 #include "chrome/browser/ui/gtk/gtk_theme_provider.h"
 #endif
 
@@ -371,7 +371,7 @@
 
 void TestingProfile::InitThemes() {
   if (!created_theme_provider_) {
-#if defined(OS_LINUX) && !defined(TOOLKIT_VIEWS)
+#if defined(TOOLKIT_GTK) && !defined(TOOLKIT_VIEWS)
     theme_provider_.reset(new GtkThemeProvider);
 #else
     theme_provider_.reset(new BrowserThemeProvider);
