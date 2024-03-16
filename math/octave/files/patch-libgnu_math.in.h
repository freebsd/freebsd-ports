--- libgnu/math.in.h.orig	2024-03-12 18:00:23 UTC
+++ libgnu/math.in.h
@@ -20,7 +20,7 @@
    would lead to many syntax errors.  */
 #if !(defined __ANDROID__ && defined _LIBCPP_MATH_H && !defined INFINITY)
 
-#ifndef _@GUARD_PREFIX@_MATH_H
+#if 1
 
 #if __GNUC__ >= 3
 @PRAGMA_SYSTEM_HEADER@
