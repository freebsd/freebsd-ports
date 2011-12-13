--- content/browser/browser_main.cc.orig	2011-11-30 22:55:59.687176328 +0200
+++ content/browser/browser_main.cc	2011-11-30 22:56:18.705178000 +0200
@@ -39,7 +39,7 @@
 #include "ui/base/l10n/l10n_util_win.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <glib-object.h>
 #endif
 
@@ -109,7 +109,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 static void GLibLogHandler(const gchar* log_domain,
                            GLogLevelFlags log_level,
                            const gchar* message,
@@ -288,7 +288,7 @@
   // of intersecting ifdefs we have.  To keep it easy to follow, there
   // are no #else branches on any #ifs.
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   // We want to call g_thread_init(), but in some codepaths (tests) it
   // is possible it has already been called.  In older versions of
   // GTK, it is an error to call g_thread_init twice; unfortunately,
