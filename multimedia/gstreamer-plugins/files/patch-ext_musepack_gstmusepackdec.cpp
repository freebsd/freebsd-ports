--- ext/musepack/gstmusepackdec.cpp.orig	Sun Nov  7 19:30:06 2004
+++ ext/musepack/gstmusepackdec.cpp	Thu Dec 16 16:31:42 2004
@@ -30,14 +30,24 @@
     GST_STATIC_CAPS ("audio/x-musepack")
     );
 
+#ifdef MPC_FIXED_POINT
+#define BASE_CAPS \
+  "audio/x-raw-int, " \
+    "signed = (bool) TRUE, " \
+    "width = (int) 32, " \
+    "depth = (int) 32"
+#else
+#define BASE_CAPS \
+  "audio/x-raw-float, " \
+    "width = (int) 32, " \
+    "buffer-frames = (int) 0"
+#endif
+
 static GstStaticPadTemplate src_template = GST_STATIC_PAD_TEMPLATE ("src",
     GST_PAD_SRC,
     GST_PAD_ALWAYS,
-    GST_STATIC_CAPS ("audio/x-raw-int, "
+    GST_STATIC_CAPS (BASE_CAPS ", "
         "endianness = (int) BYTE_ORDER, "
-        "signed = (bool) TRUE, "
-        "width = (int) 32, "
-        "depth = (int) 32, "
         "rate = (int) [ 8000, 96000 ], "
         "channels = (int) [ 1, 2 ]")
     );
@@ -352,6 +362,7 @@
 gst_musepack_stream_init (GstMusepackDec * musepackdec)
 {
   StreamInfo si = StreamInfo ();
+  GstCaps *caps;
 
   if (musepackdec->dec)
     delete musepackdec->dec;
@@ -379,15 +390,12 @@
     return FALSE;
   }
 
-  if (!gst_pad_set_explicit_caps (musepackdec->srcpad,
-           gst_caps_new_simple ("audio/x-raw-int",
-               "width", G_TYPE_INT, 32,
-               "depth", G_TYPE_INT, 32,
-               "endianness", G_TYPE_INT, G_BYTE_ORDER,
-               "channels", G_TYPE_INT, si.simple.Channels,
-               "rate", G_TYPE_INT, si.simple.SampleFreq,
-               "signed", G_TYPE_BOOLEAN, TRUE,
-               NULL))) {
+  caps = gst_caps_from_string (BASE_CAPS);
+  gst_caps_set_simple (caps,
+      "endianness", G_TYPE_INT, G_BYTE_ORDER,
+      "channels", G_TYPE_INT, si.simple.Channels,
+      "rate", G_TYPE_INT, si.simple.SampleFreq, NULL);
+  if (!gst_pad_set_explicit_caps (musepackdec->srcpad, caps)) {
     GST_ELEMENT_ERROR (musepackdec, CORE, NEGOTIATION, (NULL), (NULL));
     delete musepackdec->dec;
     musepackdec->dec = NULL;
