--- htsearch/Display.cc.orig	2023-04-10 13:24:24 UTC
+++ htsearch/Display.cc
@@ -42,7 +42,7 @@ using namespace std;
 #endif /* HAVE_STD */
 
 #include <stdio.h>
-#include <stdlib.h> // for abs
+#include <math.h> // for fabs
 #include <ctype.h>
 
 #ifndef _MSC_VER /* _WIN32 */
@@ -1541,7 +1541,7 @@ Display::buildMatchList()
 // seconds in a 365 days year). The formula gives less weight
 // as the distance between the date document and the current time
 // increases (the absolute value is for documents with future date)
-#define DATE_FACTOR(df, n, dd) ((df) * 100 / (1+(double)(abs((n) - (dd)) / 31536000)))
+#define DATE_FACTOR(df, n, dd) ((df) * 100 / (1+(double)(fabs((n) - (dd)) / 31536000)))
 	    date_score =  DATE_FACTOR(date_factor, now, thisRef->DocTime());
 	    score += date_score;
         }
