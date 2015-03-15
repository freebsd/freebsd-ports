--- src/core/libclucene-core.pc.cmake.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/libclucene-core.pc.cmake	2013-04-16 14:52:22.000000000 -0400
@@ -6,6 +6,6 @@
 Name: libclucene
 Description: CLucene - a C++ search engine, ported from the popular Apache Lucene
 Version: @CLUCENE_VERSION_MAJOR@.@CLUCENE_VERSION_MINOR@.@CLUCENE_VERSION_REVISION@.@CLUCENE_VERSION_PATCH@
-Libs: -L${prefix}/@LIB_DESTINATION@/ -lclucene-core
+Libs: -L${prefix}/@LIB_DESTINATION@/ -lclucene-core -lclucene-shared -lclucene-contribs-lib
 Cflags: -I${prefix}/include -I${prefix}/include/CLucene/ext
 ~
