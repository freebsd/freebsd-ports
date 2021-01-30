--- modules/vision/src/key-point/vpKeyPoint.cpp.orig	2021-01-30 15:50:44 UTC
+++ modules/vision/src/key-point/vpKeyPoint.cpp
@@ -2269,7 +2269,7 @@ void vpKeyPoint::initDetector(const std::string &detec
 
   if (detectorNameTmp == "SIFT") {
 #ifdef VISP_HAVE_OPENCV_XFEATURES2D
-    cv::Ptr<cv::FeatureDetector> siftDetector = cv::xfeatures2d::SIFT::create();
+    cv::Ptr<cv::FeatureDetector> siftDetector = cv::SIFT::create();
     if (!usePyramid) {
       m_detectors[detectorNameTmp] = siftDetector;
     } else {
@@ -2447,7 +2447,7 @@ void vpKeyPoint::initExtractor(const std::string &extr
 #else
   if (extractorName == "SIFT") {
 #ifdef VISP_HAVE_OPENCV_XFEATURES2D
-    m_extractors[extractorName] = cv::xfeatures2d::SIFT::create();
+    m_extractors[extractorName] = cv::SIFT::create();
 #else
     std::stringstream ss_msg;
     ss_msg << "Fail to initialize the extractor: SIFT. OpenCV version  " << std::hex << VISP_HAVE_OPENCV_VERSION
