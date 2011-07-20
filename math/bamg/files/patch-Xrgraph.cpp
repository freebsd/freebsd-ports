--- Xrgraph.cpp-orig	2011-07-19 12:50:19.000000000 -0500
+++ Xrgraph.cpp	2011-07-19 12:50:40.000000000 -0500
@@ -18,8 +18,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
-#include <iostream.h>
-#include <assert.h>
+#include <iostream>
+#include <cassert>
+using namespace std;
 
 #define MAXSHORT 0xFFFF
 
