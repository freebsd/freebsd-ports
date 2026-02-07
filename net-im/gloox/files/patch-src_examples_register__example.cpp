--- src/examples/register_example.cpp.orig	2017-08-04 16:23:26 UTC
+++ src/examples/register_example.cpp
@@ -17,8 +17,8 @@
 #include "../loghandler.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
