--- Source/WebCore/platform/graphics/gstreamer/MediaSampleGStreamer.cpp.orig	2022-09-14 04:58:10.500863000 -0700
+++ Source/WebCore/platform/graphics/gstreamer/MediaSampleGStreamer.cpp	2023-02-01 19:03:29.925503000 -0800
@@ -122,12 +122,6 @@
     }
 }
 
-PlatformSample MediaSampleGStreamer::platformSample() const
-{
-    PlatformSample sample = { PlatformSample::GStreamerSampleType, { .gstSample = m_sample.get() } };
-    return sample;
-}
-
 Ref<MediaSample> MediaSampleGStreamer::createNonDisplayingCopy() const
 {
     if (!m_sample)
