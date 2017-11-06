--- src/examples/roster_example.cpp.orig	2017-08-04 16:24:40 UTC
+++ src/examples/roster_example.cpp
@@ -22,8 +22,8 @@
 #include "../presence.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
