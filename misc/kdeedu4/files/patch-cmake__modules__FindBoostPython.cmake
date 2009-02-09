--- ../cmake/modules/FindBoostPython.cmake.orig	2008-11-04 17:12:46.000000000 +0000
+++ ../cmake/modules/FindBoostPython.cmake	2008-12-30 21:25:59.000000000 +0000
@@ -21,8 +21,8 @@
 include(CheckLibraryExists)
 
 # reset vars
-set(BOOST_PYTHON_INCLUDES)
-set(BOOST_PYTHON_LIBS)
+# set(BOOST_PYTHON_INCLUDES)
+# set(BOOST_PYTHON_LIBS)
 
 # handy arrays
 set(PYTHON_VERSIONS "python;python2.6;python2.5;python2.4;python2.3;python2.2")
