--- src/c++wrap.cc.orig	2016-07-20 16:53:48 UTC
+++ src/c++wrap.cc
@@ -26,6 +26,7 @@
 #include "c++wrap.hh"
 
 #include <unistd.h>
+#include <stdio.h>
 
 /* force use of  POSIX strerror_r instead of non-portable GNU specific */
 #ifdef _GNU_SOURCE
