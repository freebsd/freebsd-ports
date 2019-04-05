--- config.tests/khr/khr.pro.orig	2018-11-27 04:10:38 UTC
+++ config.tests/khr/khr.pro
@@ -3,4 +3,4 @@
 
 CONFIG-=qt
 
-linux:SOURCES += khr.cpp
+unix:SOURCES += khr.cpp
