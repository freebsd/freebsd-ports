--- modules/ast/src/cpp/types/test-types.cpp.orig	2026-05-19 09:32:07 UTC
+++ modules/ast/src/cpp/types/test-types.cpp
@@ -16,6 +16,7 @@
 #include <iostream>
 #include <assert.h>
 #include "alltypes.hxx"
+#include "charEncoding.h"
 
 int main(void)
 {
@@ -43,7 +44,9 @@ int main(void)
     ** types::String
     */
     types::String s42(L"42");
-    std::cout << "s42 = " << s42.get(0, 0) << std::endl;
+    char* pstrS42 = wide_string_to_UTF8(s42.get(0, 0));
+    std::cout << "s42 = " << pstrS42 << std::endl;
+    FREE(pstrS42);
     assert(wcscmp(s42.get(0, 0), L"42") == 0);
     assert(s42.isInt() == false);
     assert(s42.isDouble() == false);
