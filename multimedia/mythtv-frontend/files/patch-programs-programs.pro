--- programs/programs.pro.orig	2008-12-30 14:08:30.000000000 -0500
+++ programs/programs.pro	2008-12-30 14:08:40.000000000 -0500
@@ -10,10 +10,6 @@
     SUBDIRS += mythwelcome mythshutdown mythtranscode/replex
 }
 
-using_backend {
-    SUBDIRS += mythbackend mythfilldatabase mythtv-setup
-}
-
 using_frontend:using_backend {
     SUBDIRS += mythtranscode
 }
