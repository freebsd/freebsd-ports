--- Fix build on 16.
--- Specialization of std::is_pod is no longer allowed in modern C++.
--- std::is_pod was deprecated in C++20 and specializations are now prohibited.
--- The specialization is not necessary for the code to function correctly.
--- This fixes the build error on FreeBSD 16 with newer clang/libc++.
--- Error: 'is_pod' cannot be specialized: Users are not allowed to specialize this standard library entity

--- include/pa/exprs.h.orig	2020-03-28 00:00:00 UTC
+++ include/pa/exprs.h
@@ -40,14 +40,7 @@ namespace pa {
 class Expr;
 }
 
-namespace std {
 
-template <>
-struct is_pod<pa::Expr>: public std::false_type
-{ };
-
-}
-
 namespace pa {
 
 enum class expr_type_id: unsigned char {
