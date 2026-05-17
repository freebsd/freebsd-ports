-- Drop forbidden std::is_pod specialization for pa::Expr.
-- libc++ in newer Clang versions marks std::is_pod as non-specializable,
-- which makes this header fail to compile on FreeBSD 16.
--- include/pa/exprs.h.orig	2020-03-28 18:16:21 UTC
+++ include/pa/exprs.h
@@ -39,14 +39,6 @@ namespace pa {
 class Expr;
 }
 
-namespace std {
-
-template <>
-struct is_pod<pa::Expr>: public std::false_type
-{ };
-
-}
-
 namespace pa {
 
 enum class expr_type_id: unsigned char {
