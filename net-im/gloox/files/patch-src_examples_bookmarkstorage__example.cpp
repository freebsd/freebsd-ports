--- src/examples/bookmarkstorage_example.cpp.orig	2017-08-04 16:25:23 UTC
+++ src/examples/bookmarkstorage_example.cpp
@@ -17,8 +17,8 @@
 #include "../bookmarkstorage.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
