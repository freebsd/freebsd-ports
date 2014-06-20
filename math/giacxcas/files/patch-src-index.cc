--- src/index.cc.orig	2014-05-01 10:55:21.000000000 +0200
+++ src/index.cc	2014-05-01 10:54:07.000000000 +0200
@@ -339,7 +339,7 @@
     return true;
   }
 
-#if !defined(GIAC_NO_OPTIMIZATIONS) && (defined(GIAC_VECTOR) || (!defined(VISUALC) && !defined(__APPLE__) && !defined(BESTA_WIN32_TARGET)))
+#if !defined(GIAC_NO_OPTIMIZATIONS) && (defined(GIAC_VECTOR) || (!defined(VISUALC)&& !defined(__clang__) && !defined(__APPLE__) && !defined(BESTA_WIN32_TARGET)))
   index_t index_m::iref() const { 
     if ( (taille % 2)==0)
       return riptr->i;
