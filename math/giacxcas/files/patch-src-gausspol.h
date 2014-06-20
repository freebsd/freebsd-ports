--- src/gausspol.h.orig	2014-05-01 12:46:28.000000000 +0200
+++ src/gausspol.h	2014-05-01 12:36:38.000000000 +0200
@@ -440,7 +440,7 @@
     U u,prevu=0;
     int k;
     int count=0;
-#if defined(GIAC_NO_OPTIMIZATIONS) || ((defined(VISUALC) || defined(__APPLE__)) && !defined(GIAC_VECTOR))
+#if defined(GIAC_NO_OPTIMIZATIONS) || ((defined(VISUALC) || defined(__APPLE__) ||defined(__clang__)) && !defined(GIAC_VECTOR))
     if (0){ count=0; }
 #else
     if (pdim<=POLY_VARS){
@@ -551,7 +551,7 @@
       convert_from<T,U>(it,itend,deg,jt,0); 
       return;
     }
-#if defined(HAVE_PTHREAD_H) && !defined(EMCC)
+#if defined(HAVE_PTHREAD_H) && !defined(EMCC) &&!defined(__clang__)
     unsigned taille=itend-it;
     if (nthreads>1 
 	&& int(taille)>nthreads*1000
