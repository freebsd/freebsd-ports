--- clfdomainsplit.cpp.orig	2016-12-25 15:08:38 UTC
+++ clfdomainsplit.cpp
@@ -1,15 +1,18 @@
-#include <stdio.h>
-
+#include <cstdio>
+#include <cstdlib>
 #include <unordered_map>
 
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
