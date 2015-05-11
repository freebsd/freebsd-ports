--- src/guess.cpp.orig	2011-06-04 00:10:02 UTC
+++ src/guess.cpp
@@ -15,7 +15,8 @@
 #include "settings.h"
 
 using namespace std;
-using boost::array;
+// Macro to avoid ambiguity with std::array (C++11)
+#define array boost::array
 
 const array<string, 3> Guess::linear_traits =
                                     {{ "slope", "intercept", "avgy" }};
