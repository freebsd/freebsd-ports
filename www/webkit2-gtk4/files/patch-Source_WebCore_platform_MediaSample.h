--- Source/WebCore/platform/MediaSample.h.orig	2023-02-01 19:19:36.695484000 -0800
+++ Source/WebCore/platform/MediaSample.h	2023-02-01 19:19:54.238085000 -0800
@@ -99,7 +99,7 @@
         HasSyncInfo = 1 << 3,
     };
     virtual SampleFlags flags() const = 0;
-    virtual PlatformSample platformSample() const = 0;
+    PlatformSample platformSample() { return { PlatformSample::None, { nullptr } }; };
     virtual PlatformSample::Type platformSampleType() const = 0;
 
     struct ByteRange {
