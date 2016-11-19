https://chromium.googlesource.com/chromium/src.git/+/424584b4984bde7c831f42e9fb47f1ad583a1c46%5E%21/

--- components/url_formatter/url_formatter.cc.orig	2016-08-03 19:02:17 UTC
+++ components/url_formatter/url_formatter.cc
@@ -429,9 +429,9 @@ void IDNSpoofChecker::SetAllowedUnicodeS
   // section at
   // http://www.unicode.org/Public/security/latest/xidmodifications.txt) are
   // are added to the allowed set. The list has to be updated when a new
-  // version of Unicode is released. The current version is 8.0.0 and ICU 58
-  // will have Unicode 9.0 data.
-#if U_ICU_VERSION_MAJOR_NUM < 58
+  // version of Unicode is released. The current version is 9.0.0 and ICU 60
+  // will have Unicode 10.0 data.
+#if U_ICU_VERSION_MAJOR_NUM < 60
   const icu::UnicodeSet aspirational_scripts(
       icu::UnicodeString(
           // Unified Canadian Syllabics
@@ -445,13 +445,13 @@ void IDNSpoofChecker::SetAllowedUnicodeS
           // Yi
           "\\uA000-\\uA48C"
           // Miao
-          "\\U00016F00-\\U00016F44\\U00016F50-\\U00016F7F"
+          "\\U00016F00-\\U00016F44\\U00016F50-\\U00016F7E"
           "\\U00016F8F-\\U00016F9F]",
           -1, US_INV),
       *status);
   allowed_set.addAll(aspirational_scripts);
 #else
-#error "Update aspirational_scripts per Unicode 9.0"
+#error "Update aspirational_scripts per Unicode 10.0"
 #endif
 
   // U+0338 is included in the recommended set, while U+05F4 and U+2027 are in
