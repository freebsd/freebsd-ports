--- src/CVTracker.cpp.orig	2021-02-18 07:59:16 UTC
+++ src/CVTracker.cpp
@@ -46,20 +46,20 @@ CVTracker::CVTracker(std::string processInfoJson, Proc
 
 // Set desirable tracker method
 cv::Ptr<cv::Tracker> CVTracker::selectTracker(std::string trackerType){
-    cv::Ptr<cv::Tracker> t;
+    cv::Ptr<cv::Tracker> t = nullptr;
 
-    if (trackerType == "BOOSTING")
-        t = cv::TrackerBoosting::create();
+//    if (trackerType == "BOOSTING")
+//        t = cv::TrackerBoosting::create();
     if (trackerType == "MIL")
         t = cv::TrackerMIL::create();
     if (trackerType == "KCF")
         t = cv::TrackerKCF::create();
-    if (trackerType == "TLD")
-        t = cv::TrackerTLD::create();
-    if (trackerType == "MEDIANFLOW")
-        t = cv::TrackerMedianFlow::create();
-    if (trackerType == "MOSSE")
-        t = cv::TrackerMOSSE::create();
+//    if (trackerType == "TLD")
+//        t = cv::TrackerTLD::create();
+//    if (trackerType == "MEDIANFLOW")
+//        t = cv::TrackerMedianFlow::create();
+//    if (trackerType == "MOSSE")
+//        t = cv::TrackerMOSSE::create();
     if (trackerType == "CSRT")
         t = cv::TrackerCSRT::create();
 
@@ -163,12 +163,14 @@ bool CVTracker::initTracker(cv::Mat &frame, size_t fra
 // Update the object tracker according to frame
 bool CVTracker::trackFrame(cv::Mat &frame, size_t frameId){
     // Update the tracking result
-    bool ok = tracker->update(frame, bbox);
+    cv::Rect bboxi = bbox;
+    bool ok = tracker->update(frame, bboxi);
 
     // Add frame number and box coords if tracker finds the object
     // Otherwise add only frame number
     if (ok)
     {
+        bbox = bboxi;
         float fw = frame.size().width;
         float fh = frame.size().height;
 
