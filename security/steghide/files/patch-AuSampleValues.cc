--- src/AuSampleValues.cc.orig	Sat Aug 14 11:20:05 2004
+++ src/AuSampleValues.cc	Sat Aug 14 11:20:13 2004
@@ -21,17 +21,17 @@
 #include "AuSampleValues.h"
 
 // AuMuLawSampleValue
-const BYTE AuMuLawSampleValue::MinValue = 0 ;
-const BYTE AuMuLawSampleValue::MaxValue = BYTE_MAX ;
+template<> const BYTE AuMuLawSampleValue::MinValue = 0 ;
+template<> const BYTE AuMuLawSampleValue::MaxValue = BYTE_MAX ;
 
 // AuPCM8SampleValue
-const SBYTE AuPCM8SampleValue::MinValue = SBYTE_MIN ;
-const SBYTE AuPCM8SampleValue::MaxValue = SBYTE_MAX ;
+template <> const SBYTE AuPCM8SampleValue::MinValue = SBYTE_MIN ;
+template <> const SBYTE AuPCM8SampleValue::MaxValue = SBYTE_MAX ;
 
 // AuPCM16SampleValue
-const SWORD16 AuPCM16SampleValue::MinValue = SWORD16_MIN ;
-const SWORD16 AuPCM16SampleValue::MaxValue = SWORD16_MAX ;
+template <> const SWORD16 AuPCM16SampleValue::MinValue = SWORD16_MIN ;
+template <> const SWORD16 AuPCM16SampleValue::MaxValue = SWORD16_MAX ;
 
 // AuPCM32SampleValue
-const SWORD32 AuPCM32SampleValue::MinValue = SWORD32_MIN ;
-const SWORD32 AuPCM32SampleValue::MaxValue = SWORD32_MAX ;
+template <> const SWORD32 AuPCM32SampleValue::MinValue = SWORD32_MIN ;
+template <> const SWORD32 AuPCM32SampleValue::MaxValue = SWORD32_MAX ;
