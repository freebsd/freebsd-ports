--- lll_search.C.orig	2010-02-16 15:59:17.000000000 -0500
+++ lll_search.C	2010-02-16 16:00:58.000000000 -0500
@@ -12,24 +12,20 @@
 
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
 
 
@@ -38,7 +34,8 @@
 
 /*------------------------ Definitions ------------------------------*/
 
-
+using namespace NTL;
+using namespace std;
 
 ZZ lambda, modul, *m_primes;
 
