Subset of:
https://bugs.webkit.org/show_bug.cgi?id=278596
https://github.com/WebKit/WebKit/pull/32665
https://commits.webkit.org/282704@main

--- Source/WebCore/platform/MediaSample.h.orig	2024-08-19 06:28:39 UTC
+++ Source/WebCore/platform/MediaSample.h
@@ -63,7 +63,6 @@ struct PlatformSample {
         const MockSampleBox* mockSampleBox;
         CMSampleBufferRef cmSampleBuffer;
         GstSample* gstSample;
-        std::pair<MTPluginByteSourceRef, std::reference_wrapper<const TrackInfo>> byteRangeSample;
     } sample;
 };
 
