--- src/common/json.cc.orig	2019-12-14 20:32:28 UTC
+++ src/common/json.cc
@@ -630,7 +630,7 @@ Json JsonReader::ParseNumber() {
     // multiply zero by inf which gives nan.
     if (f != 0.0) {
       // Only use exp10 from libc on gcc+linux
-#if !defined(__GNUC__) || defined(_WIN32) || defined(__APPLE__)
+#if !defined(__GNUC__) || defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)
 #define exp10(val) std::pow(10, (val))
 #endif  // !defined(__GNUC__) || defined(_WIN32) || defined(__APPLE__)
       f *= exp10(exponent);
