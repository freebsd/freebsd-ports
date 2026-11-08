-- fix for the bug in the Gemmi project: https://github.com/project-gemmi/gemmi/issues/384#issuecomment-5789847575
-- this bug causes one testcase to fail due to duplicate C++ typeinfo objects

--- include/gemmi/third_party/tao/pegtl/parse_error.hpp.orig	2026-03-02 03:06:09 UTC
+++ include/gemmi/third_party/tao/pegtl/parse_error.hpp
@@ -14,7 +14,7 @@ namespace tao
 {
    namespace TAO_PEGTL_NAMESPACE
    {
-      struct parse_error
+      struct __attribute__((visibility("default"))) parse_error
          : public std::runtime_error
       {
          parse_error( const std::string& msg, std::vector< position >&& in_positions )
