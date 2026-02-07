--- polygon.cpp.orig	2024-03-16 22:56:04 UTC
+++ polygon.cpp
@@ -93,7 +93,7 @@ namespace { // start of anonymous namespace
 
 namespace { // start of anonymous namespace
 	struct SweepEvent;
-	struct SegmentComp : public binary_function<SweepEvent*, SweepEvent*, bool> {
+	struct SegmentComp : public __binary_function<SweepEvent*, SweepEvent*, bool> {
 		bool operator() (SweepEvent* e1, SweepEvent* e2) const;
 	};
 
@@ -116,7 +116,7 @@ namespace { // start of anonymous namespace
 		bool above (const Point& x) const { return !below (x); }
 	};
 
-	struct SweepEventComp : public binary_function<SweepEvent*, SweepEvent*, bool> {
+	struct SweepEventComp : public __binary_function<SweepEvent*, SweepEvent*, bool> {
 		bool operator() (SweepEvent* e1, SweepEvent* e2) const {
 			if (e1->p.x < e2->p.x) // Different x coordinate
 				return true;
