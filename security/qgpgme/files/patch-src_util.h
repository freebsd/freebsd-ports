Fix out-of-bounds access on empty std::string_view in _qgpgme::split.

When testing an empty string, the loop attempts to evaluate s[start]
(where start = 0) before passing it to std::addressof. With libc++
assertions enabled, accessing index 0 of a size 0 std::string_view
triggers a fatal bounds violation (SIGILL). Replacing the pointer
arithmetic with substr() safely bypasses the undefined behavior.

--- src/util.h.orig	2026-07-20 13:07:38 UTC
+++ src/util.h
@@ -40,7 +40,6 @@
 
 #include <gpgme.h>
 
-#include <memory>
 #include <string>
 #include <vector>
 
@@ -76,7 +75,7 @@ static inline std::vector<std::string_view> split(cons
         if (end == s.npos) {
             end = s.size();
         }
-        result.emplace_back(std::addressof(s[start]), end - start);
+        result.emplace_back(s.substr(start, end - start));
         start = end + 1;
     } while (end != s.size());
     return result;
