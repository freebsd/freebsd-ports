--- lib/math.in.h.orig	2026-02-23 04:26:00 UTC
+++ lib/math.in.h
@@ -51,7 +51,7 @@
 /* This file uses _GL_INLINE_HEADER_BEGIN, _GL_INLINE, _GL_ATTRIBUTE_CONST,
    GNULIB_POSIXCHECK, HAVE_RAW_DECL_*.  */
 #if !_GL_CONFIG_H_INCLUDED
- #error "Please include config.h first."
+ # include "config.h" 
 #endif
 
 /* On OpenVMS, NAN, INFINITY, and HUGEVAL macros are defined in <fp.h>.  */
