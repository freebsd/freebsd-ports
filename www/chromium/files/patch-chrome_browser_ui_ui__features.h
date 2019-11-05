--- chrome/browser/ui/ui_features.h.orig	2019-10-21 19:06:24 UTC
+++ chrome/browser/ui/ui_features.h
@@ -46,7 +46,7 @@ extern const base::Feature kWebFooterExperiment;
 
 extern const base::Feature kWebUITabStrip;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const base::Feature kEnableDbusAndX11StatusIcons;
 #endif
 
