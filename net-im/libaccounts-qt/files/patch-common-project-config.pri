--- common-project-config.pri.orig	2020-07-09 18:52:52 UTC
+++ common-project-config.pri
@@ -19,7 +19,7 @@ UI_SOURCES_DIR  = ui/src
 # we don't like warnings...
 #QMAKE_CXXFLAGS *= -Werror
 
-CONFIG += c++11
+CONFIG += c++17
 
 #-----------------------------------------------------------------------------
 # setup the installation prefix
