--- src/conversions.h.orig	2011-09-23 16:57:57.000000000 +0800
+++ src/conversions.h	2011-09-23 16:58:09.000000000 +0800
@@ -45,14 +45,14 @@ namespace internal {
 const int kMaxSignificantDigits = 772;
 
 
-static bool isDigit(int x, int radix) {
+static inline bool isDigit(int x, int radix) {
   return (x >= '0' && x <= '9' && x < '0' + radix)
       || (radix > 10 && x >= 'a' && x < 'a' + radix - 10)
       || (radix > 10 && x >= 'A' && x < 'A' + radix - 10);
 }
 
 
-static double SignedZero(bool negative) {
+static inline double SignedZero(bool negative) {
   return negative ? -0.0 : 0.0;
 }
 
