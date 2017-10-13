--- third_party/chromium/src/base/strings/string_util.h.orig	2017-09-13 21:56:00 UTC
+++ third_party/chromium/src/base/strings/string_util.h
@@ -377,7 +377,7 @@ inline Char HexDigitToInt(Char c) {
 
 // Returns true if it's a whitespace character.
 inline bool IsWhitespace(wchar_t c) {
-  return wcschr(base::kWhitespaceWide, c) != NULL;
+  return (::wcschr(base::kWhitespaceWide, c) != (wchar_t *)NULL);
 }
 
 // Return a byte string in human-readable format with a unit suffix. Not
