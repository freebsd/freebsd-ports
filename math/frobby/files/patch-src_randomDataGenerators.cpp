--- src/randomDataGenerators.cpp.orig	2018-09-05 21:14:15 UTC
+++ src/randomDataGenerators.cpp
@@ -25,6 +25,7 @@
 
 #include <limits>
 #include <ctime>
+#include <unistd.h>
 
 void generateLinkedListIdeal(BigIdeal& ideal, size_t variableCount) {
   VarNames names(variableCount);
