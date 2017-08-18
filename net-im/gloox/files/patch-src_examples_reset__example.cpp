--- src/examples/reset_example.cpp.orig	2017-08-04 16:27:13 UTC
+++ src/examples/reset_example.cpp
@@ -18,8 +18,8 @@
 #include "../logsink.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
