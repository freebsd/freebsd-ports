--- modules/plugin/base/public/nptypes.h.orig	Sun Sep  5 18:56:55 2004
+++ modules/plugin/base/public/nptypes.h	Thu Oct 21 19:29:29 2004
@@ -73,7 +73,7 @@
   #if defined(bsdi) || defined(OPENBSD)
   typedef u_int32_t uint32_t;
 
-  #if defined(bsdi)
+  #if defined(bsdi) || defined(__FreeBSD__)
   #if !defined(__cplusplus)
     typedef int bool;
   #endif
