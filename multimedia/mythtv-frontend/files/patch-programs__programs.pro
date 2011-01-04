--- programs/programs.pro.orig	2010-11-01 14:01:30.000000000 +0100
+++ programs/programs.pro	2010-11-01 14:07:41.000000000 +0100
@@ -11,8 +11,4 @@
     !mingw: SUBDIRS += mythtranscode/replex
 }
 
-using_backend {
-    SUBDIRS += mythbackend mythfilldatabase mythtv-setup scripts
-}
-
 using_mythtranscode: SUBDIRS += mythtranscode
