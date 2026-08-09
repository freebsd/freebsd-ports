--- src/utility.hpp.orig	2020-06-22 17:54:57 UTC
+++ src/utility.hpp
@@ -153,7 +153,7 @@ namespace literals {
  * @return
  *	A Formatter instance
  */
-constexpr Formatter<16384> operator "" _fmt(char const * const fmt, size_t const) {
+constexpr Formatter<16384> operator ""_fmt(char const * const fmt, size_t const) {
 	return {fmt};
 }
 } /* namespace literals */
