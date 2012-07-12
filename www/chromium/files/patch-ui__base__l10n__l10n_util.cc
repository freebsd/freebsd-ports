--- ui/base/l10n/l10n_util.cc.orig	2012-06-05 23:55:13.000000000 +0300
+++ ui/base/l10n/l10n_util.cc	2012-06-06 00:00:11.000000000 +0300
@@ -33,7 +33,7 @@
 #include "base/android/locale_utils.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include <glib.h>
 #endif
 
@@ -417,7 +417,7 @@
   if (!pref_locale.empty())
     candidates.push_back(pref_locale);
 
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   // If we're on a different Linux system, we have glib.
 
   // GLib implements correct environment variable parsing with
