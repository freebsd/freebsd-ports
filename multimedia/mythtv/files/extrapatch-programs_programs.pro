Disable backend components for multimedia/mythtv-frontend

--- programs/programs.pro.orig	2018-01-11 12:39:22 UTC
+++ programs/programs.pro
@@ -15,13 +15,4 @@ using_frontend {
     !mingw:!win32-msvc*: SUBDIRS += mythtranscode/external/replex
 }
 
-using_backend {
-    SUBDIRS += mythbackend mythfilldatabase mythtv-setup 
-    SUBDIRS += mythmetadatalookup
-
-    !win32-msvc*:SUBDIRS += scripts
-    !mingw:!win32-msvc*: SUBDIRS += mythfilerecorder
-    !mingw:!win32-msvc*: SUBDIRS += mythexternrecorder
-}
-
 using_mythtranscode: SUBDIRS += mythtranscode
