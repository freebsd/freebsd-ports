--- ./programs/programs.pro.orig	2008-01-29 15:17:31.000000000 -0500
+++ ./programs/programs.pro	2009-04-22 21:05:21.000000000 -0400
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
