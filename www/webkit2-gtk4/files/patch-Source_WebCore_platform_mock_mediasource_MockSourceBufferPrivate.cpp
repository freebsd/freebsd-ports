--- Source/WebCore/platform/mock/mediasource/MockSourceBufferPrivate.cpp.orig	2023-02-01 19:18:31.889914000 -0800
+++ Source/WebCore/platform/mock/mediasource/MockSourceBufferPrivate.cpp	2023-02-01 19:18:53.986792000 -0800
@@ -60,7 +60,6 @@
     AtomString trackID() const override { return m_id; }
     size_t sizeInBytes() const override { return sizeof(m_box); }
     SampleFlags flags() const override;
-    PlatformSample platformSample() const override;
     PlatformSample::Type platformSampleType() const override { return PlatformSample::MockSampleBoxType; }
     FloatSize presentationSize() const override { return FloatSize(); }
     void dump(PrintStream&) const override;
@@ -82,12 +81,6 @@
     if (m_box.isNonDisplaying())
         flags |= IsNonDisplaying;
     return SampleFlags(flags);
-}
-
-PlatformSample MockMediaSample::platformSample() const
-{
-    PlatformSample sample = { PlatformSample::MockSampleBoxType, { &m_box } };
-    return sample;
 }
 
 void MockMediaSample::dump(PrintStream& out) const
