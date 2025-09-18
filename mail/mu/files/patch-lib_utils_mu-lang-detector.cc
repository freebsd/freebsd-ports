--- lib/utils/mu-lang-detector.cc.orig	2025-09-13 18:31:43.331335000 +0200
+++ lib/utils/mu-lang-detector.cc	2025-09-13 18:32:32.363670000 +0200
@@ -25,8 +25,8 @@
 // Dummy implementation
 Option<Language> Mu::detect_language(const std::string& txt) { return Nothing; }
 #else
-#include <cld2/public/compact_lang_det.h>
-#include <cld2/public/encodings.h>
+#include <cld/public/compact_lang_det.h>
+#include <cld/public/encodings.h>
 
 Option<Language>
 Mu::detect_language(const std::string& txt)
