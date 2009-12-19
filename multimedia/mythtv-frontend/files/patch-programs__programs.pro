--- programs/programs.pro.orig	2009-10-15 23:39:07.000000000 +0000
+++ programs/programs.pro	2009-10-15 23:39:19.000000000 +0000
@@ -9,10 +9,6 @@
     SUBDIRS += mythwelcome mythshutdown mythtranscode/replex
 }
 
-using_backend {
-    SUBDIRS += mythbackend mythfilldatabase mythtv-setup scripts
-}
-
 using_frontend:using_backend {
     SUBDIRS += mythtranscode
 }
