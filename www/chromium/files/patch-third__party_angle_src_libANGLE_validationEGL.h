--- third_party/angle/src/libANGLE/validationEGL.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/angle/src/libANGLE/validationEGL.h
@@ -121,7 +121,7 @@ inline const AttributeMap PackParam<const AttributeMap
 
 // In a 32-bit environment the EGLAttrib and EGLint types are the same. We need to mask out one of
 // the two specializations to avoid having an override ambiguity.
-#if defined(ANGLE_IS_64_BIT_CPU)
+#if defined(ANGLE_IS_64_BIT_CPU) || defined(ANGLE_PLATFORM_OPENBSD)
 template <>
 inline const AttributeMap PackParam<const AttributeMap &, const EGLAttrib *>(
     const EGLAttrib *attribs)
