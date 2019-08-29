--- Lib/Portability.hpp.orig	2018-12-01 20:14:14 UTC
+++ Lib/Portability.hpp
@@ -25,11 +25,11 @@
 // Detect compiler
 
 #ifndef __APPLE__
-# define __APPLE__ 0
+//# define __APPLE__ 0
 #endif
 
 #ifndef __CYGWIN__
-# define __CYGWIN__ 0
+//# define __CYGWIN__ 0
 #endif
 
 //////////////////////////////////////////////////////
