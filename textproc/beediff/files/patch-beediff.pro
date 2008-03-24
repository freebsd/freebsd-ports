--- ./beediff.pro.orig	2008-03-16 14:40:25.000000000 +0300
+++ ./beediff.pro	2008-03-23 11:23:02.000000000 +0300
@@ -1,8 +1,5 @@
 TEMPLATE =  app
 CONFIG +=  qt release warn_on x11
-QMAKE_CXXFLAGS = -march=pentium
-QMAKE_CXXFLAGS_DEBUG = -O0 -g
-QMAKE_CXXFLAGS_RELEASE = -O3
 OBJECTS_DIR =  ./tmp
 MOC_DIR =  ./tmp
 SOURCES =  \
