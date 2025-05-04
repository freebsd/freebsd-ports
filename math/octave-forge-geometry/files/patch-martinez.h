--- martinez.h.orig	2024-03-16 22:56:04 UTC
+++ martinez.h
@@ -37,7 +37,7 @@ class Martinez { (private)
 	enum PolygonType { SUBJECT, CLIPPING };
 
 	struct SweepEvent;
-	struct SegmentComp : public binary_function<SweepEvent*, SweepEvent*, bool> { // for sorting edges in the sweep line
+	struct SegmentComp : public __binary_function<SweepEvent*, SweepEvent*, bool> { // for sorting edges in the sweep line
 		bool operator() (SweepEvent* e1, SweepEvent* e2) const;
 	};
 	
@@ -64,7 +64,7 @@ class Martinez { (private)
 	
 	static void print (SweepEvent& e); // This function is intended for debugging purposes
 
-	struct SweepEventComp : public binary_function<SweepEvent*, SweepEvent*, bool> { // for sortening events
+	struct SweepEventComp : public __binary_function<SweepEvent*, SweepEvent*, bool> { // for sortening events
 		bool operator() (SweepEvent* e1, SweepEvent* e2) const;
 	};
 
