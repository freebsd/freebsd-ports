--- clfmerge.cpp.orig	Tue Jan  8 17:15:37 2002
+++ clfmerge.cpp	Tue Jan  8 17:14:06 2002
@@ -1,17 +1,26 @@
-#include <stdio.h>
+#include <cstdio>
+
+#if defined(_LIBCPP_VERSION)
+#include <unordered_map>
+#else
 #include <ext/hash_map>
-#include <stdlib.h>
+#endif
+
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
 
 struct eqstr
 {
@@ -19,7 +28,11 @@
   { return strcmp(s1, s2) == 0; }
 };
 
+#if defined(_LIBCPP_VERSION)
+unordered_map<const char *, const char *, hash<const char *>, eqstr> months;
+#else
 hash_map<const char *, const char *, hash<const char *>, eqstr> months;
+#endif
 
 class LogFile
 {
@@ -207,7 +220,7 @@
   unsigned int map_items = 0;
   bool set_map_items = false, domain_mangling = false;
   int int_c;
-  optind = 0;
+  optind = 1;
   while(-1 != (int_c = getopt(argc, argv, "b:hd")) )
   {
     switch(char(int_c))
