--- third_party/WebKit/Source/wtf/DateMath.cpp.orig	2013-11-08 07:50:10.000000000 +0100
+++ third_party/WebKit/Source/wtf/DateMath.cpp	2013-11-15 12:55:05.000000000 +0100
@@ -80,6 +80,8 @@
 #include "StringExtras.h"
 
 #include <algorithm>
+#include <cstdlib>
+#include <stdlib.h>
 #include <limits.h>
 #include <limits>
 #include <stdint.h>
@@ -665,7 +667,7 @@
         return 0;
     if (*postParsePosition != ':' || (postParsePosition - currentPosition) != 2)
         return 0;
-    tzHoursAbs = labs(tzHours);
+    tzHoursAbs = std::labs(tzHours);
     currentPosition = postParsePosition + 1;
 
     if (!isASCIIDigit(*currentPosition))
@@ -979,7 +981,7 @@
                 return std::numeric_limits<double>::quiet_NaN();
 
             int sgn = (o < 0) ? -1 : 1;
-            o = abs(o);
+            o = std::abs(o);
             if (*dateString != ':') {
                 if (o >= 24)
                     offset = ((o / 100) * 60 + (o % 100)) * sgn;
@@ -1077,7 +1079,7 @@
     stringBuilder.append(' ');
 
     stringBuilder.append(utcOffset > 0 ? '+' : '-');
-    int absoluteUTCOffset = abs(utcOffset);
+    int absoluteUTCOffset = std::abs(utcOffset);
     stringBuilder.append(twoDigitStringFromNumber(absoluteUTCOffset / 60));
     stringBuilder.append(twoDigitStringFromNumber(absoluteUTCOffset % 60));
 
