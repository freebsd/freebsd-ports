--- ui/base/l10n/l10n_util.cc.orig	2012-11-28 04:02:47.000000000 +0200
+++ ui/base/l10n/l10n_util.cc	2012-12-04 22:11:25.000000000 +0200
@@ -33,7 +33,7 @@
 #include "base/android/locale_utils.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib.h>
 #endif
 
@@ -419,7 +419,7 @@
   if (!pref_locale.empty())
     candidates.push_back(pref_locale);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // If we're on a different Linux system, we have glib.
 
   // GLib implements correct environment variable parsing with
