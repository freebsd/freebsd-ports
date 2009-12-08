--- libs/libFreeMat/Malloc.cpp.orig	2009-10-08 09:45:59.000000000 +0700
+++ libs/libFreeMat/Malloc.cpp	2009-10-08 09:47:56.000000000 +0700
@@ -21,6 +21,7 @@
 #include "Exception.hpp"
 #include <stdlib.h>
 #include <stdio.h>
+#include <cstring>
 
 
 void* Malloc(int count) {
