--- y4mdenoise/MotionSearcher.hh.orig	2010-07-26 05:06:56.000000000 +0900
+++ y4mdenoise/MotionSearcher.hh	2012-06-12 19:23:18.000000000 +0900
@@ -2196,7 +2196,7 @@
 	{
 		// This region is too small to be bothered with.
 		// Just get rid of it.
-		DeleteRegion (a_pRegion);
+		this->DeleteRegion (a_pRegion);
 	}
 	else
 	{
