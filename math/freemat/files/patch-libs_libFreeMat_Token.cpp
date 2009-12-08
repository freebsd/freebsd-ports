--- libs/libFreeMat/Token.cpp.orig	2009-10-08 09:49:12.000000000 +0700
+++ libs/libFreeMat/Token.cpp	2009-10-08 09:50:12.000000000 +0700
@@ -2,6 +2,7 @@
 #include "Serialize.hpp"
 #include <iostream>
 #include <errno.h>
+#include <climits>
 
 // These must appear as sequential token numbers
 string fm_reserved[22] = {
