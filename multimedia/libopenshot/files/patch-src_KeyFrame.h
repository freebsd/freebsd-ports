--- src/KeyFrame.h.orig	2023-04-19 22:01:02 UTC
+++ src/KeyFrame.h
@@ -16,6 +16,7 @@
 #include <iostream>
 #include <vector>
 
+#include "Fraction.h"
 #include "Point.h"
 #include "Json.h"
 
@@ -66,8 +67,8 @@ namespace openshot {
 		/// Constructor which adds a supplied vector of Points
 		Keyframe(const std::vector<openshot::Point>& points);
 
-		/// Destructor
-		~Keyframe();
+        /// Destructor
+        ~Keyframe();
 
 		/// Add a new point on the key-frame.  Each point has a primary coordinate, a left handle, and a right handle.
 		void AddPoint(Point p);
@@ -92,6 +93,9 @@ namespace openshot {
 
 		/// Get the rounded LONG value at a specific index
 		int64_t GetLong(int64_t index) const;
+
+		/// Get the fraction that represents how many times this value is repeated in the curve
+		Fraction GetRepeatFraction(int64_t index) const;
 
 		/// Get the change in Y value (from the previous Y value)
 		double GetDelta(int64_t index) const;
