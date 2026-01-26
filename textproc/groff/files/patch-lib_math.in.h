--- lib/math.in.h.orig	2023-07-05 20:58:27 UTC
+++ lib/math.in.h
@@ -54,7 +54,7 @@
 #endif
 
 #ifndef _GL_INLINE_HEADER_BEGIN
- #error "Please include config.h first."
+# include "config.h"
 #endif
 _GL_INLINE_HEADER_BEGIN
 #ifndef _GL_MATH_INLINE
