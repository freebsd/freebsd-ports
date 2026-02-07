--- header.cc.orig	1993-08-02 05:28:21.000000000 +0900
+++ header.cc	2014-01-22 10:38:20.000000000 +0900
@@ -11,7 +11,8 @@
 //  to the comments or the code of this program, but if reported
 //  to me then an attempt will be made to fix them.
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <stdlib.h> 
 #include <ctype.h>
