--- /dev/null	2014-01-29 03:00:00.000000000 +0000
+++ build/pkgs/eclib/fbsd-patch-src_libsrc_eclib_interface.h	2014-01-29 03:01:19.000000000 +0000
@@ -0,0 +1,10 @@
+--- src/libsrc/eclib/interface.h-orig	2013-04-26 23:46:24.000000000 +0000
++++ src/libsrc/eclib/interface.h	2013-04-26 23:47:09.000000000 +0000
+@@ -48,6 +48,7 @@
+ #include <iterator>
+ using namespace std;
+ #include "templates.h"
++#include <stdint.h>
+ 
+ #ifndef MININT
+ #define MININT numeric_limits<int>::min()
