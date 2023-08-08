--- work/webkitgtk-2.38.3/Source/WebCore/platform/graphics/gstreamer/MediaSampleGStreamer.h.orig	2023-02-01 19:14:20.412727000 -0800
+++ work/webkitgtk-2.38.3/Source/WebCore/platform/graphics/gstreamer/MediaSampleGStreamer.h	2023-02-01 19:14:27.116674000 -0800
@@ -51,7 +51,6 @@
     void setTimestamps(const MediaTime&, const MediaTime&) override;
     Ref<MediaSample> createNonDisplayingCopy() const override;
     SampleFlags flags() const override { return m_flags; }
-    PlatformSample platformSample() const override;
     PlatformSample::Type platformSampleType() { return PlatformSample::GStreamerSampleType; }
     void dump(PrintStream&) const override;
 
