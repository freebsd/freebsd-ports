--- config.tests/snappy/snappy.pro.orig	2018-11-27 04:10:38 UTC
+++ config.tests/snappy/snappy.pro
@@ -1,3 +1,3 @@
-linux:SOURCES += snappy.cpp
+unix:SOURCES += snappy.cpp
 LIBS += -lsnappy
 CONFIG -= qt
