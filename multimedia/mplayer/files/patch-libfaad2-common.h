--- libfaad2/common.h.orig	Thu Mar 10 15:33:19 2005
+++ libfaad2/common.h	Thu Mar 10 15:34:38 2005
@@ -328,7 +328,9 @@
   }
 
 
-  #if defined(_WIN32) && !defined(__MINGW32__)
+  #if defined(HAVE_LRINTF)
+    #define HAS_LRINTF
+  #elif defined(_WIN32) && !defined(__MINGW32__)
     #define HAS_LRINTF
     static INLINE int lrintf(float f)
     {
