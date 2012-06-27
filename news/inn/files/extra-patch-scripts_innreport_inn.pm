--- scripts/innreport_inn.pm.orig	2012-03-14 01:09:58.000000000 +0800
+++ scripts/innreport_inn.pm	2012-03-14 01:17:41.000000000 +0800
@@ -2197,7 +2197,7 @@
 # Compare 2 dates (+hour)
 sub datecmp {
   # ex: "May 12 06"   for May 12, 6:00am
-  local($[) = 0;
+
   # The 2 dates are near. The range is less than a few days that's why we
   # can cheat to determine the order. It is only important if one date
   # is in January and the other in December.
