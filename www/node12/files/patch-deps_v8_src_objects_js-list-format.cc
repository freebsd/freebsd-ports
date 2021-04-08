https://github.com/v8/v8/commit/035c305ce7761f51328b45f1bd83e26aef267c9d

../deps/v8/src/objects/js-list-format.cc:172:55: error: 'createInstance' is a private member of 'icu::ListFormatter'
  icu::ListFormatter* formatter = icu::ListFormatter::createInstance(
                                  ~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~
/usr/local/include/unicode/listformatter.h:267:27: note: declared private here
    static ListFormatter* createInstance(const Locale& locale, const char* style, UErrorCode& errorCode);
                          ^

--- deps/v8/src/objects/js-list-format.cc.orig	2021-04-06 17:17:08 UTC
+++ deps/v8/src/objects/js-list-format.cc
@@ -29,46 +29,27 @@ namespace v8 {
 namespace internal {
 
 namespace {
-const char* kStandard = "standard";
-const char* kOr = "or";
-const char* kUnit = "unit";
-const char* kStandardShort = "standard-short";
-const char* kOrShort = "or-short";
-const char* kUnitShort = "unit-short";
-const char* kStandardNarrow = "standard-narrow";
-const char* kOrNarrow = "or-narrow";
-const char* kUnitNarrow = "unit-narrow";
 
-const char* GetIcuStyleString(JSListFormat::Style style,
-                              JSListFormat::Type type) {
+UListFormatterWidth GetIcuWidth(JSListFormat::Style style) {
+  switch (style) {
+    case JSListFormat::Style::LONG:
+      return ULISTFMT_WIDTH_WIDE;
+    case JSListFormat::Style::SHORT:
+      return ULISTFMT_WIDTH_SHORT;
+    case JSListFormat::Style::NARROW:
+      return ULISTFMT_WIDTH_NARROW;
+  }
+  UNREACHABLE();
+}
+
+UListFormatterType GetIcuType(JSListFormat::Type type) {
   switch (type) {
     case JSListFormat::Type::CONJUNCTION:
-      switch (style) {
-        case JSListFormat::Style::LONG:
-          return kStandard;
-        case JSListFormat::Style::SHORT:
-          return kStandardShort;
-        case JSListFormat::Style::NARROW:
-          return kStandardNarrow;
-      }
+      return ULISTFMT_TYPE_AND;
     case JSListFormat::Type::DISJUNCTION:
-      switch (style) {
-        case JSListFormat::Style::LONG:
-          return kOr;
-        case JSListFormat::Style::SHORT:
-          return kOrShort;
-        case JSListFormat::Style::NARROW:
-          return kOrNarrow;
-      }
+      return ULISTFMT_TYPE_OR;
     case JSListFormat::Type::UNIT:
-      switch (style) {
-        case JSListFormat::Style::LONG:
-          return kUnit;
-        case JSListFormat::Style::SHORT:
-          return kUnitShort;
-        case JSListFormat::Style::NARROW:
-          return kUnitNarrow;
-      }
+      return ULISTFMT_TYPE_UNITS;
   }
   UNREACHABLE();
 }
@@ -170,7 +151,7 @@ MaybeHandle<JSListFormat> JSListFormat::New(Isolate* i
   icu::Locale icu_locale = r.icu_locale;
   UErrorCode status = U_ZERO_ERROR;
   icu::ListFormatter* formatter = icu::ListFormatter::createInstance(
-      icu_locale, GetIcuStyleString(style_enum, type_enum), status);
+      icu_locale, GetIcuType(type_enum), GetIcuWidth(style_enum), status);
   if (U_FAILURE(status)) {
     delete formatter;
     FATAL("Failed to create ICU list formatter, are ICU data files missing?");
