--- utils/igbhead.cc.orig	Tue Oct 15 02:20:12 2002
+++ utils/igbhead.cc	Tue Oct 15 02:20:30 2002
@@ -11,6 +11,9 @@
 #include<string>
 #include "IGBheader.h"
 #include "cmdline.h"
+#include <iostream>
+
+using namespace std;
 
 void output_header( IGBheader* );
 
