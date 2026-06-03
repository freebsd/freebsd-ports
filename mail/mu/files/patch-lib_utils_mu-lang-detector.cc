--- lib/utils/mu-lang-detector.cc.orig	2025-09-29 18:02:55 UTC
+++ lib/utils/mu-lang-detector.cc
@@ -25,8 +25,8 @@ Option<Language> Mu::detect_language(const std::string
 // Dummy implementation
 Option<Language> Mu::detect_language(const std::string& txt) { return Nothing; }
 #else
-#include <cld2/public/compact_lang_det.h>
-#include <cld2/public/encodings.h>
+#include <cld/public/compact_lang_det.h>
+#include <cld/public/encodings.h>
 
 Option<Language>
 Mu::detect_language(const std::string& txt)
