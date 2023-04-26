--- src/KeyFrame.cpp.orig	2023-04-19 22:01:02 UTC
+++ src/KeyFrame.cpp
@@ -15,12 +15,12 @@
 
 #include <algorithm>   // For std::lower_bound, std::move_backward
 #include <functional>  // For std::less, std::less_equal, etc…
-#include <utility>	 // For std::swap
-#include <numeric>	 // For std::accumulate
-#include <cassert>	 // For assert()
-#include <cmath>	   // For fabs, round
-#include <iostream>	// For std::cout
-#include <iomanip>	 // For std::setprecision
+#include <utility>     // For std::swap
+#include <numeric>     // For std::accumulate
+#include <cassert>     // For assert()
+#include <cmath>       // For fabs, round
+#include <iostream>    // For std::cout
+#include <iomanip>     // For std::setprecision
 
 using namespace std;
 using namespace openshot;
@@ -122,8 +122,8 @@ Keyframe::Keyframe(const std::vector<openshot::Point>&
 
 // Destructor
 Keyframe::~Keyframe() {
-	Points.clear();
-	Points.shrink_to_fit();
+    Points.clear();
+    Points.shrink_to_fit();
 }
 
 // Add a new point on the key-frame.  Each point has a primary coordinate,
@@ -291,41 +291,27 @@ int64_t Keyframe::GetLong(int64_t index) const {
 // Get the direction of the curve at a specific index (increasing or decreasing)
 bool Keyframe::IsIncreasing(int index) const
 {
-	if (index <= 1) {
-		// Determine direction of frame 1 (and assume previous frames have same direction)
-		index = 1;
-	} else  if (index >= GetLength()) {
-		// Determine direction of last valid frame # (and assume next frames have same direction)
-		index = GetLength() - 1;
+	if (index < 1 || (index + 1) >= GetLength()) {
+		return true;
 	}
-
-	// Get current index value
-	const double current_value = GetValue(index);
-
-	// Iterate from current index to next significant value change
-	int attempts = 1;
-	while (attempts < 600 && index + attempts <= GetLength()) {
-		// Get next value
-		const double next_value = GetValue(index + attempts);
-
-		// Is value significantly different
-		const double diff = next_value - current_value;
-		if (fabs(diff) > 0.0001) {
-			if (diff < 0.0) {
-				// Decreasing value found next
-				return false;
-			} else {
-				// Increasing value found next
-				return true;
-			}
-		}
-
-		// increment attempt
-		attempts++;
+	std::vector<Point>::const_iterator candidate =
+		std::lower_bound(begin(Points), end(Points), static_cast<double>(index), IsPointBeforeX);
+	if (candidate == end(Points)) {
+		return false; // After the last point, thus constant.
 	}
-
-	// If no next value found, assume increasing values
-	return true;
+	if ((candidate->co.X == index) || (candidate == begin(Points))) {
+		++candidate;
+	}
+	int64_t const value = GetLong(index);
+	do {
+		if (value < round(candidate->co.Y)) {
+			return true;
+		} else if (value > round(candidate->co.Y)) {
+			return false;
+		}
+		++candidate;
+	} while (candidate != end(Points));
+	return false;
 }
 
 // Generate JSON string of this object
@@ -388,12 +374,116 @@ void Keyframe::SetJsonValue(const Json::Value root) {
 		}
 }
 
+// Get the fraction that represents how many times this value is repeated in the curve
+// This is depreciated and will be removed soon.
+Fraction Keyframe::GetRepeatFraction(int64_t index) const {
+	// Frame numbers (index) outside of the "defined" range of this
+	// keyframe result in a 1/1 default value.
+	if (index < 1 || (index + 1) >= GetLength()) {
+		return Fraction(1,1);
+	}
+	assert(Points.size() > 1); // Due to ! ((index + 1) >= GetLength) there are at least two points!
+
+	// First, get the value at the given frame and the closest point
+	// to the right.
+	int64_t const current_value = GetLong(index);
+	std::vector<Point>::const_iterator const candidate =
+		std::lower_bound(begin(Points), end(Points), static_cast<double>(index), IsPointBeforeX);
+	assert(candidate != end(Points)); // Due to the (index + 1) >= GetLength check above!
+
+	// Calculate how many of the next values are going to be the same:
+	int64_t next_repeats = 0;
+	std::vector<Point>::const_iterator i = candidate;
+	// If the index (frame number) is the X coordinate of the closest
+	// point, then look at the segment to the right; the "current"
+	// segement is not interesting because we're already at the last
+	// value of it.
+	if (i->co.X == index) {
+		++i;
+	}
+	// Skip over "constant" (when rounded) segments.
+	bool all_constant = true;
+	for (; i != end(Points); ++i) {
+		if (current_value != round(i->co.Y)) {
+			all_constant = false;
+			break;
+		}
+	}
+	if (! all_constant) {
+		// Found a point which defines a segment which will give a
+		// different value than the current value.  This means we
+		// moved at least one segment to the right, thus we cannot be
+		// at the first point.
+		assert(i != begin(Points));
+		Point const left = *(i - 1);
+		Point const right = *i;
+		int64_t change_at;
+		if (current_value < round(i->co.Y)) {
+			change_at = SearchBetweenPoints(left, right, current_value, std::less_equal<double>{});
+		} else {
+			assert(current_value > round(i->co.Y));
+			change_at = SearchBetweenPoints(left, right, current_value, std::greater_equal<double>{});
+		}
+		next_repeats = change_at - index;
+	} else {
+		// All values to the right are the same!
+		next_repeats = Points.back().co.X - index;
+	}
+
+	// Now look to the left, to the previous values.
+	all_constant = true;
+	i = candidate;
+	if (i != begin(Points)) {
+		// The binary search below assumes i to be the left point;
+		// candidate is the right point of the current segment
+		// though. So change this if possible. If this branch is NOT
+		// taken, then we're at/before the first point and all is
+		// constant!
+		--i;
+	}
+	int64_t previous_repeats = 0;
+	// Skip over constant (when rounded) segments!
+	for (; i != begin(Points); --i) {
+		if (current_value != round(i->co.Y)) {
+			all_constant = false;
+			break;
+		}
+	}
+	// Special case when skipped until the first point, but the first
+	// point is actually different.  Will not happen if index is
+	// before the first point!
+	if (current_value != round(i->co.Y)) {
+		assert(i != candidate);
+		all_constant = false;
+	}
+	if (! all_constant) {
+		// There are at least two points, and we're not at the end,
+		// thus the following is safe!
+		Point const left = *i;
+		Point const right = *(i + 1);
+		int64_t change_at;
+		if (current_value > round(left.co.Y)) {
+			change_at = SearchBetweenPoints(left, right, current_value, std::less<double>{});
+		} else {
+			assert(current_value < round(left.co.Y));
+			change_at = SearchBetweenPoints(left, right, current_value, std::greater<double>{});
+		}
+		previous_repeats = index - change_at;
+	} else {
+		// Every previous value is the same (rounded) as the current
+		// value.
+		previous_repeats = index;
+	}
+	int64_t total_repeats = previous_repeats + next_repeats;
+	return Fraction(previous_repeats, total_repeats);
+}
+
 // Get the change in Y value (from the previous Y value)
 double Keyframe::GetDelta(int64_t index) const {
-	if (index < 1) return 0.0;
-	if (index == 1 && !Points.empty()) return Points[0].co.Y;
-	if (index >= GetLength()) return 0.0;
-	return GetValue(index) - GetValue(index - 1);
+	if (index < 1) return 0;
+	if (index == 1 && ! Points.empty()) return Points[0].co.Y;
+	if (index >= GetLength()) return 0;
+	return GetLong(index) - GetLong(index - 1);
 }
 
 // Get a point at a specific index
@@ -410,7 +500,7 @@ Point const & Keyframe::GetPoint(int64_t index) const 
 int64_t Keyframe::GetLength() const {
 	if (Points.empty()) return 0;
 	if (Points.size() == 1) return 1;
-	return round(Points.back().co.X);
+	return round(Points.back().co.X) + 1;
 }
 
 // Get the number of points (i.e. # of points)
@@ -461,46 +551,50 @@ void Keyframe::UpdatePoint(int64_t index, Point p) {
 }
 
 void Keyframe::PrintPoints(std::ostream* out) const {
-	*out << std::right << std::setprecision(4) << std::setfill(' ');
-	for (const auto& p : Points) {
-		*out << std::defaultfloat
-			 << std::setw(6) << p.co.X
-			 << std::setw(14) << std::fixed << p.co.Y
-			 << '\n';
-	}
-	*out << std::flush;
+    *out << std::right << std::setprecision(4) << std::setfill(' ');
+    for (const auto& p : Points) {
+        *out << std::defaultfloat
+             << std::setw(6) << p.co.X
+             << std::setw(14) << std::fixed << p.co.Y
+             << '\n';
+    }
+    *out << std::flush;
 }
 
 void Keyframe::PrintValues(std::ostream* out) const {
-	// Column widths
-	std::vector<int> w{10, 12, 8, 11, 19};
+    // Column widths
+    std::vector<int> w{10, 12, 8, 11, 19};
 
-	*out << std::right << std::setfill(' ') << std::setprecision(4);
-	// Headings
-	*out << "│"
-		 << std::setw(w[0]) << "Frame# (X)" << " │"
-		 << std::setw(w[1]) << "Y Value" << " │"
-		 << std::setw(w[2]) << "Delta Y" << " │ "
-		 << std::setw(w[3]) << "Increasing?" << std::right
-		 << "│\n";
-	// Divider
-	*out << "├───────────"
-		 << "┼─────────────"
-		 << "┼─────────"
-		 << "┼────────────┤\n";
+    *out << std::right << std::setfill(' ') << std::setprecision(4);
+    // Headings
+    *out << "│"
+         << std::setw(w[0]) << "Frame# (X)" << " │"
+         << std::setw(w[1]) << "Y Value" << " │"
+         << std::setw(w[2]) << "Delta Y" << " │ "
+         << std::setw(w[3]) << "Increasing?" << " │ "
+         << std::setw(w[4]) << std::left << "Repeat Fraction" << std::right
+         << "│\n";
+    // Divider
+    *out << "├───────────"
+         << "┼─────────────"
+         << "┼─────────"
+         << "┼─────────────"
+         << "┼────────────────────┤\n";
 
-	for (int64_t i = 1; i <= GetLength(); ++i) {
-		*out << "│"
-			 << std::setw(w[0]-2) << std::defaultfloat << i
-			 << (Contains(Point(i, 1)) ? " *" : "  ") << " │"
-			 << std::setw(w[1]) << std::fixed << GetValue(i) << " │"
-			 << std::setw(w[2]) << std::defaultfloat << std::showpos
-								<< GetDelta(i) << " │ " << std::noshowpos
-			 << std::setw(w[3])
-			 << (IsIncreasing(i) ? "true" : "false") << std::right << "│\n";
-	}
-	*out << " * = Keyframe point (non-interpolated)\n";
-	*out << std::flush;
+    for (int64_t i = 1; i < GetLength(); ++i) {
+        *out << "│"
+             << std::setw(w[0]-2) << std::defaultfloat << i
+             << (Contains(Point(i, 1)) ? " *" : "  ") << " │"
+             << std::setw(w[1]) << std::fixed << GetValue(i) << " │"
+             << std::setw(w[2]) << std::defaultfloat << std::showpos
+                                << GetDelta(i) << " │ " << std::noshowpos
+             << std::setw(w[3])
+             << (IsIncreasing(i) ? "true" : "false") << " │ "
+             << std::setw(w[4]) << std::left << GetRepeatFraction(i)
+                                << std::right << "│\n";
+    }
+    *out << " * = Keyframe point (non-interpolated)\n";
+    *out << std::flush;
 }
 
 
