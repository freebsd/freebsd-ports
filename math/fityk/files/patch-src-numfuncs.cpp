--- src/numfuncs.cpp.orig	Sun May 22 01:35:44 2005
+++ src/numfuncs.cpp	Mon Jul  4 01:27:08 2005
@@ -5,6 +5,8 @@
 #include "data.h"
 #include "numfuncs.h"
 
+#include <algorithm>
+
 using namespace std;
 
 vector<B_point>::iterator 
