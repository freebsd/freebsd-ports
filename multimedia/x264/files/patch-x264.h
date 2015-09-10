Our stdint.h is a symlink to sys/stdint.h so we need to teach x264
the header guard of the sys/stdint.h file.

Accepted upstream, see https://reviews.freebsd.org/D2863 for details.
--- x264.h.orig	2015-06-19 08:05:22.728325000 +0200
+++ x264.h	2015-06-19 08:05:39.433879000 +0200
@@ -29,7 +29,7 @@
 #define X264_X264_H
 
 #if !defined(_STDINT_H) && !defined(_STDINT_H_) && !defined(_STDINT_H_INCLUDED) && !defined(_STDINT) &&\
-    !defined(_INTTYPES_H) && !defined(_INTTYPES_H_) && !defined(_INTTYPES)
+    !defined(_SYS_STDINT_H_) && !defined(_INTTYPES_H) && !defined(_INTTYPES_H_) && !defined(_INTTYPES)
 # ifdef _MSC_VER
 #  pragma message("You must include stdint.h or inttypes.h before x264.h")
 # else
