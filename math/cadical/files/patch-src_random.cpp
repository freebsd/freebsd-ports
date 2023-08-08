--- src/random.cpp.orig	2023-01-03 21:27:48 UTC
+++ src/random.cpp
@@ -1,5 +1,7 @@
 #include "internal.hpp"
 
+#include <netinet/in.h>
+
 /*------------------------------------------------------------------------*/
 
 // Our random number generator is seeded by default (i.e., in the default
