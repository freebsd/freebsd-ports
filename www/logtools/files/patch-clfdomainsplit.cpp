--- clfdomainsplit.cpp.orig	Mon Jun  9 10:56:27 2003
+++ clfdomainsplit.cpp	Mon Jun  9 10:56:47 2003
@@ -1,19 +1,23 @@
-#include <stdio.h>
+#include <cstdio>
 
-#if (__GNUC__ >= 3)
-#include <ext/hash_map>
+#if defined(_LIBCPP_VERSION)
+#include <unordered_map>
 #else
-#include <hash_map>
+#include <ext/hash_map>
 #endif
 
+#include <cstdlib>
 #include <unistd.h>
 #include <cstring>
 #include <vector>
-#include <ctype.h>
+#include <cctype>
+#include <string>
 #include "logtools.h"
 
 using namespace std;
+#if !defined(_LIBCPP_VERSION)
 using namespace __gnu_cxx;
+#endif
 
 // MAX_FDS is the maximum number of files that will be directly written to
 // by one process
@@ -166,7 +170,11 @@
   size_t operator()(const string str) const { return hash<const char *>()(str.c_str()); }
 };
 
+#if defined(_LIBCPP_VERSION)
+typedef unordered_map<const string, FILE **, hash_string, eqstr> HASH_TYPE;
+#else
 typedef hash_map<const string, FILE **, hash_string, eqstr> HASH_TYPE;
+#endif
 HASH_TYPE fd_map;
 
 typedef FILE * PFILE;
