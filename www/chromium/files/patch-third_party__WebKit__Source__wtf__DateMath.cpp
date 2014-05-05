--- ./third_party/WebKit/Source/wtf/DateMath.cpp.orig	2014-04-24 22:39:59.000000000 +0200
+++ ./third_party/WebKit/Source/wtf/DateMath.cpp	2014-04-24 23:23:47.000000000 +0200
@@ -80,6 +80,7 @@
 #include "StringExtras.h"
 
 #include <algorithm>
+#include <cstdlib>
 #include <limits.h>
 #include <limits>
 #include <math.h>
@@ -785,7 +786,7 @@
                 return std::numeric_limits<double>::quiet_NaN();
 
             int sgn = (o < 0) ? -1 : 1;
-            o = abs(o);
+            o = std::abs(o);
             if (*dateString != ':') {
                 if (o >= 24)
                     offset = ((o / 100) * 60 + (o % 100)) * sgn;
@@ -874,7 +875,7 @@
     stringBuilder.append(' ');
 
     stringBuilder.append(utcOffset > 0 ? '+' : '-');
-    int absoluteUTCOffset = abs(utcOffset);
+    int absoluteUTCOffset = std::abs(utcOffset);
     stringBuilder.append(twoDigitStringFromNumber(absoluteUTCOffset / 60));
     stringBuilder.append(twoDigitStringFromNumber(absoluteUTCOffset % 60));
 
