--- src/help.cpp.orig	Fri Aug 19 17:58:00 2005
+++ src/help.cpp	Fri Aug 19 17:59:15 2005
@@ -1,7 +1,9 @@
 #include <stdio.h>
 #include "constant.hpp"
 #include "help.hpp"
-#include <iostream.h>
+#include <iostream>
+
+using namespace std;
 
 void Hello(void) {
    cout << "\nFTrack " << FVersion << "  " << Copyright << "\n";
