--- libfaad2/common.h.orig	Thu Jun 15 10:39:27 2006
+++ libfaad2/common.h	Thu Jun 15 10:40:18 2006
@@ -318,8 +318,9 @@
       *y2 = MUL_F(x2, c1) - MUL_F(x1, c2);
   }
 
-
-  #if defined(_WIN32) && !defined(__MINGW32__) && !defined(HAVE_LRINTF)
+  #if defined(HAVE_LRINTF)
+    #define HAS_LRINTF
+  #elif defined(_WIN32) && !defined(__MINGW32__) && !defined(HAVE_LRINTF)
     #define HAS_LRINTF
     static INLINE int lrintf(float f)
     {
