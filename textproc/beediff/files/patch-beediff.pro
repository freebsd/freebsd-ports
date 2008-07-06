--- ./beediff.pro.orig	2008-06-29 15:19:35.000000000 +0400
+++ ./beediff.pro	2008-07-05 16:18:49.000000000 +0400
@@ -1,7 +1,5 @@
 TEMPLATE =  app
 CONFIG +=  qt release warn_on x11
-QMAKE_CXXFLAGS_DEBUG = -O0 -g
-QMAKE_CXXFLAGS_RELEASE = -O3
 OBJECTS_DIR =  ./tmp
 MOC_DIR =  ./tmp
 SOURCES =  \
