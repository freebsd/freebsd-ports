--- strip.h.orig	Fri Aug  6 09:09:27 1999
+++ strip.h	Wed Mar 31 20:15:31 2004
@@ -2,8 +2,9 @@
 
 #ifndef __JUNK_FILTER_H__
 #define __JUNK_FILTER_H__
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
+using namespace std;
 #include <stdlib.h>
 #include "tune.h"
 
