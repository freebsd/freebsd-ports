--- lll_spect.C.orig	2010-02-16 15:51:33.000000000 -0500
+++ lll_spect.C	2010-02-16 15:55:48.000000000 -0500
@@ -14,30 +14,29 @@
 
 /*-------------Libraries (needs Victor Shoups NTL-Lib----------------*/
 
-#include <iostream.h>
+#include <iostream>
 
-#include <fstream.h>
+#include <fstream>
 
 #include <time.h>
 
 #include <sys/resource.h>
 
-#include <math.h>
+#include <cmath>
 
 #include <float.h>
 
-#include <NTL/ZZ.h>
-
 #include <NTL/RR.h>
 
-#include <NTL/mat_ZZ.h>
-
 #include <NTL/LLL.h>
 
 
 
 /*------------------------ Definitions ------------------------------*/
 
+using namespace NTL;
+using namespace std;
+
 ZZ mult, modul; 
 
 const int dim_max = 24;
