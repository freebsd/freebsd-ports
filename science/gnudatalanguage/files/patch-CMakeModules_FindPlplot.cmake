--- CMakeModules/FindPlplot.cmake.orig	2015-04-22 19:37:22 UTC
+++ CMakeModules/FindPlplot.cmake
@@ -9,8 +9,8 @@
 #
 
 
-find_library(PLPLOT_LIBRARY NAMES plplotd)
-find_library(PLPLOTCXX_LIBRARY NAMES plplotcxxd)
+find_library(PLPLOT_LIBRARY NAMES plplot)
+find_library(PLPLOTCXX_LIBRARY NAMES plplotcxx)
 set(PLPLOT_LIBRARIES ${PLPLOT_LIBRARY} ${PLPLOTCXX_LIBRARY})
 find_path(PLPLOT_INCLUDE_DIR NAMES plplot/plplot.h)
 include(FindPackageHandleStandardArgs)
