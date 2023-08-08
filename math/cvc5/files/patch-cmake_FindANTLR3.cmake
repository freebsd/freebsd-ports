--- cmake/FindANTLR3.cmake.orig	2022-12-12 22:42:47 UTC
+++ cmake/FindANTLR3.cmake
@@ -18,7 +18,7 @@
 
 include(deps-helper)
 
-find_file(ANTLR3_JAR NAMES antlr-3.4-complete.jar PATH_SUFFIXES share/java/)
+set(ANTLR3_JAR ${FREEBSD_DISTDIR}/antlr-3.4-complete.jar)
 find_path(ANTLR3_INCLUDE_DIR NAMES antlr3.h)
 find_library(ANTLR3_LIBRARIES NAMES antlr3c)
 
