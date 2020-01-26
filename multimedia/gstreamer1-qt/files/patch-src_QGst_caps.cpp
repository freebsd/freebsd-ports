The GStreamer headers #define a version of gst_caps_copy() with the
internal implementation. This prevents the normal C++ type conversion
that would happen when the gst_caps_copy() function is called normally.
Explicitly get the inner pointer (*caps2 doesn't work) to match
the implementation API that is now exposed by the #define.

This patch is needed for GStreamer 1.16+

--- src/QGst/caps.cpp.orig	2014-07-08 18:38:36 UTC
+++ src/QGst/caps.cpp
@@ -54,7 +54,7 @@ QString Caps::toString() const
 
 void Caps::append(const CapsPtr & caps2)
 {
-    gst_caps_append(object<GstCaps>(), gst_caps_copy(caps2));
+    gst_caps_append(object<GstCaps>(), gst_caps_copy(caps2.operator->()));
 }
 
 CapsPtr Caps::merge(CapsPtr & caps2)
