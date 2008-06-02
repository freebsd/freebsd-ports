--- src/src.pro.orig	2008-05-09 13:23:13.000000000 -0400
+++ src/src.pro	2008-05-09 13:34:37.000000000 -0400
@@ -18,6 +18,7 @@
 }
 
 win32 : QMAKE_WIN32 = 1
+freebsd-* : QMAKE_FREEBSD = 1
 
 #-------------------------------------------------------------------------------
 #   Platform Specific: Unix (except MacOS X)
@@ -49,6 +50,10 @@
                 HEADERS += Application_X11.h
             }
             SOURCES += main_unix.cpp
+            isEqual(QMAKE_FREEBSD,1){
+                CONFIG -= precompile_header
+                QMAKE_CXXFLAGS += -include keepassx.h
+            }
         }
 
 
