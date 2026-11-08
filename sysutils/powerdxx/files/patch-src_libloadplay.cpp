--- src/libloadplay.cpp.orig	2020-06-22 17:54:57 UTC
+++ src/libloadplay.cpp
@@ -126,7 +126,7 @@ inline int strcmp(char const * const s1, char const (&
  * @return
  *	A regular expression
  */
-inline std::regex operator "" _r(char const * const str, size_t const len) {
+inline std::regex operator ""_r(char const * const str, size_t const len) {
 	return {str, len, std::regex::ECMAScript};
 }
 
