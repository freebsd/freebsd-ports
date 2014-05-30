--- build/cmake/macros/SystemSpecificInformations.cmake.orig	2013-09-19 15:12:10.000000000 -0500
+++ build/cmake/macros/SystemSpecificInformations.cmake	2013-10-20 12:04:52.000000000 -0500
@@ -241,7 +241,8 @@
     endif(EXISTS "/etc/issue")
 
   elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
-    string(REGEX MATCH "(([0-9]+)\\.([0-9]+))-RELEASE" FREEBSD "${CMAKE_SYSTEM_VERSION}")
+    # Match x.x-RELEASE, x.x-BETA1, etc.
+    string(REGEX MATCH "(([0-9]+)\\.([0-9]+))-([A-Z0-9])+" FREEBSD "${CMAKE_SYSTEM_VERSION}")
     set( FREEBSD_RELEASE "${CMAKE_MATCH_1}" )
     set( FREEBSD_MAJOR "${CMAKE_MATCH_2}" )
     set( FREEBSD_MINOR "${CMAKE_MATCH_3}" )
@@ -259,6 +260,14 @@
       set( CONDOR_FREEBSD7 ON )
     elseif(FREEBSD_MAJOR MATCHES "8" )
       set( CONDOR_FREEBSD8 ON )
+    elseif(FREEBSD_MAJOR MATCHES "9" )
+      set( CONDOR_FREEBSD9 ON )
+    elseif(FREEBSD_MAJOR MATCHES "10" )
+      set( CONDOR_FREEBSD10 ON )
+      set( CONDOR_FREEBSD9 ON )
+    elseif(FREEBSD_MAJOR MATCHES "11" )
+      set( CONDOR_FREEBSD11 ON )
+      set( CONDOR_FREEBSD9 ON )
     endif()
     if( CMAKE_SYSTEM_PROCESSOR MATCHES "amd64" )
       set( SYS_ARCH "x86_64")
