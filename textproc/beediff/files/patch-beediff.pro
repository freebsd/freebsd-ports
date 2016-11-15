--- beediff.pro.orig	2008-09-14 07:47:41 UTC
+++ beediff.pro
@@ -1,7 +1,5 @@
 TEMPLATE =  app
 CONFIG +=  qt release warn_on x11
-QMAKE_CXXFLAGS_DEBUG = -O0 -g
-QMAKE_CXXFLAGS_RELEASE = -O3
 OBJECTS_DIR =  ./tmp
 MOC_DIR =  ./tmp
 SOURCES =  \
