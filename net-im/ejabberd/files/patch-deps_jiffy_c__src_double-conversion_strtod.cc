--- deps/jiffy/c_src/double-conversion/strtod.cc.orig	2020-04-10 09:23:29 UTC
+++ deps/jiffy/c_src/double-conversion/strtod.cc
@@ -38,7 +38,9 @@ namespace double_conversion {
 // 2^53 = 9007199254740992.
 // Any integer with at most 15 decimal digits will hence fit into a double
 // (which has a 53bit significand) without loss of precision.
+#if defined(DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS)
 static const int kMaxExactDoubleIntegerDecimalDigits = 15;
+#endif
 // 2^64 = 18446744073709551616 > 10^19
 static const int kMaxUint64DecimalDigits = 19;
 
@@ -55,6 +57,7 @@ static const int kMinDecimalPower = -324;
 static const uint64_t kMaxUint64 = UINT64_2PART_C(0xFFFFFFFF, FFFFFFFF);
 
 
+#if defined(DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS)
 static const double exact_powers_of_ten[] = {
   1.0,  // 10^0
   10.0,
@@ -82,6 +85,7 @@ static const double exact_powers_of_ten[] = {
   10000000000000000000000.0
 };
 static const int kExactPowersOfTenSize = ARRAY_SIZE(exact_powers_of_ten);
+#endif
 
 // Maximum number of significant digits in the decimal representation.
 // In fact the value is 772 (see conversions.cc), but to give us some margin
