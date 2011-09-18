--- v8/src/extensions/experimental/number-format.cc.orig	2011-08-30 12:19:09.000000000 +0300
+++ v8/src/extensions/experimental/number-format.cc	2011-09-10 17:32:54.000000000 +0300
@@ -36,6 +36,8 @@
 #include "unicode/numfmt.h"
 #include "unicode/uchar.h"
 #include "unicode/ucurr.h"
+#include "unicode/unum.h"
+#include "unicode/uversion.h"
 
 namespace v8 {
 namespace internal {
@@ -231,6 +233,8 @@
 }
 
 // Generates ICU number format pattern from given skeleton.
+// TODO(cira): Remove once ICU includes equivalent method
+// (see http://bugs.icu-project.org/trac/ticket/8610).
 static icu::DecimalFormat* CreateFormatterFromSkeleton(
     const icu::Locale& icu_locale,
     const icu::UnicodeString& skeleton,
@@ -251,6 +255,7 @@
     // Case of non-consecutive U+00A4 is taken care of in i18n.js.
     int32_t end_index = skeleton.lastIndexOf(currency_symbol, index);
 
+#if (U_ICU_VERSION_MAJOR_NUM == 4) && (U_ICU_VERSION_MINOR_NUM <= 6)
     icu::NumberFormat::EStyles style;
     switch (end_index - index) {
       case 0:
@@ -262,6 +267,19 @@
       default:
         style = icu::NumberFormat::kPluralCurrencyStyle;
     }
+#else  // ICU version is 4.8 or above (we ignore versions below 4.0).
+    UNumberFormatStyle style;
+    switch (end_index - index) {
+      case 0:
+        style = UNUM_CURRENCY;
+        break;
+      case 1:
+        style = UNUM_CURRENCY_ISO;
+        break;
+      default:
+        style = UNUM_CURRENCY_PLURAL;
+    }
+#endif
 
     base_format = static_cast<icu::DecimalFormat*>(
         icu::NumberFormat::createInstance(icu_locale, style, *status));
