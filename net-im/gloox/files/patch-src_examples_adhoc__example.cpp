--- src/examples/adhoc_example.cpp.orig	2017-08-04 16:24:08 UTC
+++ src/examples/adhoc_example.cpp
@@ -20,8 +20,8 @@
 #include "../logsink.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
