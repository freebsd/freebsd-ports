--- Source/JavaScriptCore/runtime/MathCommon.cpp.orig	2024-10-21 09:00:02 UTC
+++ Source/JavaScriptCore/runtime/MathCommon.cpp
@@ -635,7 +635,7 @@ JSC_DEFINE_NOEXCEPT_JIT_OPERATION(f64_nearest, double,
     return std::nearbyint(operand);
 }
 
-#if OS(LINUX) && !defined(__GLIBC__)
+#if OS(UNIX) && !defined(__GLIBC__)
 static inline float roundevenf(float operand)
 {
     float rounded = roundf(operand);
