--- programs/programs.pro.orig	2012-03-19 06:39:10.000000000 +0100
+++ programs/programs.pro	2012-03-21 23:55:00.883069453 +0100
@@ -11,9 +11,4 @@
     !mingw: SUBDIRS += mythtranscode/replex
 }
 
-using_backend {
-    SUBDIRS += mythbackend mythfilldatabase mythtv-setup scripts
-    SUBDIRS += mythmetadatalookup
-}
-
 using_mythtranscode: SUBDIRS += mythtranscode
