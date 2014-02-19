--- src/examples/e2ee_server.cpp.orig
+++ src/examples/e2ee_server.cpp
@@ -12,8 +12,8 @@
 using namespace gloox;
 
 #include <unistd.h>
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
