Disable backend components for multimedia/mythtv-frontend

--- programs/programs.pro.orig	2018-01-11 12:39:22 UTC
+++ programs/programs.pro
@@ -19,21 +19,6 @@
     unix:QMAKE_EXTRA_TARGETS += mythfrontend-test
 }
 
-using_backend {
-    SUBDIRS += mythbackend mythfilldatabase mythtv-setup 
-    SUBDIRS += mythmetadatalookup
-
-    !win32-msvc*:SUBDIRS += scripts
-    !mingw:!win32-msvc*: SUBDIRS += mythfilerecorder
-    !mingw:!win32-msvc*: SUBDIRS += mythexternrecorder
-
-    # unit tests mythbackend
-    mythbackend-test.depends = sub-mythbackend
-    mythbackend-test.target = buildtestmythbackend
-    mythbackend-test.commands = cd mythbackend/test && $(QMAKE) && $(MAKE)
-    unix:QMAKE_EXTRA_TARGETS += mythbackend-test
-}
-
 using_mythtranscode: SUBDIRS += mythtranscode
