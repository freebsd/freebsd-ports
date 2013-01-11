--- chrome/app/chrome_main_delegate.cc.orig	2012-12-04 23:34:32.000000000 +0200
+++ chrome/app/chrome_main_delegate.cc	2012-12-04 23:35:37.000000000 +0200
@@ -264,7 +264,7 @@
       // Mac needs them for the plugin process name.
       process_type == switches::kPluginProcess ||
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
