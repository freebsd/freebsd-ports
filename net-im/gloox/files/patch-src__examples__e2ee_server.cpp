--- src/examples/e2ee_server.cpp.orig	2015-08-11 14:37:51 UTC
+++ src/examples/e2ee_server.cpp
@@ -24,8 +24,8 @@
 using namespace gloox;
 
 #include <unistd.h>
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
