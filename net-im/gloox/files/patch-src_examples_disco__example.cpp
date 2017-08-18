--- src/examples/disco_example.cpp.orig	2017-08-04 16:23:56 UTC
+++ src/examples/disco_example.cpp
@@ -19,8 +19,8 @@
 #include "../loghandler.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
