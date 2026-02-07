--- src/examples/vcard_example.cpp.orig	2017-08-04 16:26:37 UTC
+++ src/examples/vcard_example.cpp
@@ -21,8 +21,8 @@
 #include "../vcard.h"
 using namespace gloox;
 
-#include <stdio.h>
-#include <locale.h>
+#include <ctime>
+#include <clocale>
 #include <string>
 
 #include <cstdio> // [s]print[f]
