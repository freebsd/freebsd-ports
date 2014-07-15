--- include/FXParallel.h.orig	2014-07-15 12:35:48.000000000 +0200
+++ include/FXParallel.h	2014-07-15 12:35:18.000000000 +0200
@@ -287,7 +287,7 @@
   const FXuval size((sizeof(FXParallelLoopFunctor<Functor,Index>)+sizeof(FXulong)-1)/sizeof(FXulong));
   if(fm<to){
     FXTaskGroup group(pool);
-    FXlong space[128*size];
+    FXlong space[128*(sizeof(FXParallelLoopFunctor<Functor,Index>)+sizeof(FXulong)-1)/sizeof(FXulong)];
     Index nits=1+(to-fm-1)/by,ni,c;
     if(nc>128) nc=128;
     if(nc>nits) nc=nits;
