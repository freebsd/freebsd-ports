--- base/i18n/icu_util.h.orig	2016-05-21 17:19:29 UTC
+++ base/i18n/icu_util.h
@@ -11,6 +11,10 @@
 #include "base/i18n/base_i18n_export.h"
 #include "build/build_config.h"
 
+#define ICU_UTIL_DATA_FILE   0
+#define ICU_UTIL_DATA_SHARED 1
+#define ICU_UTIL_DATA_STATIC 2
+
 namespace base {
 namespace i18n {
 
