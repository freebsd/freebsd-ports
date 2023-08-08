--- Source/WebCore/platform/graphics/gstreamer/MediaSampleGStreamer.h.orig	2023-02-01 19:38:13.797696000 -0800
+++ Source/WebCore/platform/graphics/gstreamer/MediaSampleGStreamer.h	2023-02-01 19:38:28.181230000 -0800
@@ -51,7 +51,6 @@
     void setTimestamps(const MediaTime&, const MediaTime&) override;
     Ref<MediaSample> createNonDisplayingCopy() const override;
     SampleFlags flags() const override { return m_flags; }
-    PlatformSample platformSample() const override;
     PlatformSample::Type platformSampleType() const override { return PlatformSample::GStreamerSampleType; }
     void dump(PrintStream&) const override;
 
