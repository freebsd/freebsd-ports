--- clfmerge.cpp.orig	2016-12-25 14:50:06 UTC
+++ clfmerge.cpp
@@ -1,17 +1,20 @@
-#include <stdio.h>
+#include <cstdio>
 #include <unordered_map>
-#include <stdlib.h>
+#include <cstdlib>
 #include <map>
 #include <cstring>
 #include <unistd.h>
-#include <ctype.h>
+#include <cctype>
+#include <string>
 
 #include "logtools.h"
 
 #define BUF_SIZE 4096
 
 using namespace std;
+#if !defined(_LIBCPP_VERSION)
 using namespace __gnu_cxx;
+#endif
 
 struct hashing_func {
   unsigned long operator()(const char *key) const
@@ -215,7 +218,7 @@ int main(int argc, char **argv)
   unsigned int map_items = 0;
   bool set_map_items = false, domain_mangling = false, verbose = false;
   int int_c;
-  optind = 0;
+  optind = 1;
   while(-1 != (int_c = getopt(argc, argv, "b:hdv")) )
   {
     switch(char(int_c))
@@ -350,6 +353,6 @@ int main(int argc, char **argv)
       } while(!items[0]->getLine());
     }
   }
-  delete items;
+  delete[] items;
   return 0;
 }
