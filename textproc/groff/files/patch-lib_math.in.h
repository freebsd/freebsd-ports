--- lib/math.in.h.orig	2018-12-23 14:34:15 UTC
+++ lib/math.in.h
@@ -34,7 +34,7 @@
 #endif
 
 #ifndef _GL_INLINE_HEADER_BEGIN
- #error "Please include config.h first."
+# include "config.h"
 #endif
 _GL_INLINE_HEADER_BEGIN
 #ifndef _GL_MATH_INLINE
