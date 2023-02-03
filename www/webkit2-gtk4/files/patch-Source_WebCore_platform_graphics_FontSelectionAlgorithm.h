XXX libstdc++ from gcc-4.9.4 doesn't yet decorate std::min/std::max
with constexpr

Index: Source/WebCore/platform/graphics/FontSelectionAlgorithm.h
--- Source/WebCore/platform/graphics/FontSelectionAlgorithm.h.orig
+++ Source/WebCore/platform/graphics/FontSelectionAlgorithm.h
@@ -49,7 +49,11 @@ class FontSelectionValue { (public)
     explicit constexpr FontSelectionValue(float);
 
     // Precision can be lost, but value will be clamped to the representable range.
+#if defined(__GLIBCXX__) && __GLIBCXX__ <= 20160726L
+    static inline    FontSelectionValue clampFloat(float);
+#else
     static constexpr FontSelectionValue clampFloat(float);
+#endif
 
     // Since floats have 23 mantissa bits, every value can be represented losslessly.
     constexpr operator float() const;
@@ -125,7 +129,11 @@ constexpr FontSelectionValue FontSelectionValue::minim
     return { std::numeric_limits<BackingType>::min(), RawTag::RawTag };
 }
 
+#if defined(__GLIBCXX__) && __GLIBCXX__ <= 20160726L
+inline    FontSelectionValue FontSelectionValue::clampFloat(float value)
+#else
 constexpr FontSelectionValue FontSelectionValue::clampFloat(float value)
+#endif
 {
     return FontSelectionValue { std::max<float>(minimumValue(), std::min<float>(value, maximumValue())) };
 }
