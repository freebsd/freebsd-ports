--- src/intlist.hxx.orig	2008-08-10 20:45:21.000000000 -0500
+++ src/intlist.hxx	2008-08-10 20:47:28.000000000 -0500
@@ -50,7 +50,8 @@
 
 #include <stdlib.h>
 #include <time.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "gdt.h"
 #include "defs.hxx"
