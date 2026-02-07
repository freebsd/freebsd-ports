--- src/dn.cpp.orig	2025-06-03 15:55:22 UTC
+++ src/dn.cpp
@@ -215,6 +215,9 @@ static std::pair<std::optional<std::string_view>, std:
         /* hexstring */
         stringv.remove_prefix(1);
         auto endHex = stringv.find_first_not_of("1234567890abcdefABCDEF"sv);
+        if (endHex == std::string_view::npos) {
+            endHex = stringv.size();
+        }
         auto value = parseHexString(stringv.substr(0, endHex));
         if (!value.has_value()) {
             return {};
