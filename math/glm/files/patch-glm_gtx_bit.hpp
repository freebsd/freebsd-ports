This is needed to fix x11-wm/gamescope with glm 1.0.1

https://github.com/g-truc/glm/issues/1269

--- glm/gtx/bit.hpp.orig	2024-02-27 17:19:47 UTC
+++ glm/gtx/bit.hpp
@@ -46,7 +46,7 @@ namespace glm
 	/// @see gtc_round
 	/// @see gtx_bit
 	template<typename genIUType>
-	GLM_DEPRECATED GLM_FUNC_DECL genIUType powerOfTwoAbove(genIUType Value);
+	GLM_FUNC_DECL genIUType powerOfTwoAbove(genIUType Value);
 
 	/// Return the power of two number which value is just higher the input value.
 	/// Deprecated, use ceilPowerOfTwo from GTC_round instead
@@ -54,7 +54,7 @@ namespace glm
 	/// @see gtc_round
 	/// @see gtx_bit
 	template<length_t L, typename T, qualifier Q>
-	GLM_DEPRECATED GLM_FUNC_DECL vec<L, T, Q> powerOfTwoAbove(vec<L, T, Q> const& value);
+	GLM_FUNC_DECL vec<L, T, Q> powerOfTwoAbove(vec<L, T, Q> const& value);
 
 	/// Return the power of two number which value is just lower the input value.
 	/// Deprecated, use floorPowerOfTwo from GTC_round instead
@@ -62,7 +62,7 @@ namespace glm
 	/// @see gtc_round
 	/// @see gtx_bit
 	template<typename genIUType>
-	GLM_DEPRECATED GLM_FUNC_DECL genIUType powerOfTwoBelow(genIUType Value);
+	GLM_FUNC_DECL genIUType powerOfTwoBelow(genIUType Value);
 
 	/// Return the power of two number which value is just lower the input value.
 	/// Deprecated, use floorPowerOfTwo from GTC_round instead
@@ -70,7 +70,7 @@ namespace glm
 	/// @see gtc_round
 	/// @see gtx_bit
 	template<length_t L, typename T, qualifier Q>
-	GLM_DEPRECATED GLM_FUNC_DECL vec<L, T, Q> powerOfTwoBelow(vec<L, T, Q> const& value);
+	GLM_FUNC_DECL vec<L, T, Q> powerOfTwoBelow(vec<L, T, Q> const& value);
 
 	/// Return the power of two number which value is the closet to the input value.
 	/// Deprecated, use roundPowerOfTwo from GTC_round instead
@@ -78,7 +78,7 @@ namespace glm
 	/// @see gtc_round
 	/// @see gtx_bit
 	template<typename genIUType>
-	GLM_DEPRECATED GLM_FUNC_DECL genIUType powerOfTwoNearest(genIUType Value);
+	GLM_FUNC_DECL genIUType powerOfTwoNearest(genIUType Value);
 
 	/// Return the power of two number which value is the closet to the input value.
 	/// Deprecated, use roundPowerOfTwo from GTC_round instead
@@ -86,7 +86,7 @@ namespace glm
 	/// @see gtc_round
 	/// @see gtx_bit
 	template<length_t L, typename T, qualifier Q>
-	GLM_DEPRECATED GLM_FUNC_DECL vec<L, T, Q> powerOfTwoNearest(vec<L, T, Q> const& value);
+	GLM_FUNC_DECL vec<L, T, Q> powerOfTwoNearest(vec<L, T, Q> const& value);
 
 	/// @}
 } //namespace glm
